#ifndef __bootstrap_hpp
#define __bootstrap_hpp__

#include "boxedcpp.hpp"
#include "register_function.hpp"

template<typename Ret, typename P1, typename P2>
Ret add(P1 p1, P2 p2)
{
  return p1 + p2;
}

template<typename Ret, typename P1, typename P2>
Ret subtract(P1 p1, P2 p2)
{
  return p1 - p2;
}

template<typename Ret, typename P1, typename P2>
Ret divide(P1 p1, P2 p2)
{
  return p1 / p2;
}


template<typename Ret, typename P1, typename P2>
Ret multiply(P1 p1, P2 p2)
{
  return p1 * p2;
}

template<typename P1, typename P2>
bool bool_and(P1 p1, P2 p2)
{
  return p1 && p2;
}

template<typename P1, typename P2>
bool bool_or(P1 p1, P2 p2)
{
  return p1 || p2;
}

template<typename P1, typename P2>
P1 &assign(P1 &p1, const P2 &p2)
{
  return (p1 = p2);
}

template<typename P1, typename P2>
bool equals(P1 p1, P2 p2)
{
  return p1 == p2;
}

template<typename P1, typename P2>
bool not_equals(P1 p1, P2 p2)
{
  return p1 != p2;
}

template<typename P1, typename P2>
bool less_than(P1 p1, P2 p2)
{
  return p1 < p2;
}

template<typename P1, typename P2>
bool greater_than(P1 p1, P2 p2)
{
  return p1 > p2;
}

template<typename P1, typename P2>
bool less_than_equals(P1 p1, P2 p2)
{
  return p1 <= p2;
}

template<typename P1, typename P2>
bool greater_than_equals(P1 p1, P2 p2)
{
  return p1 >= p2;
}

template<typename P1, typename P2>
P1 &timesequal(P1 &p1, const P2 &p2)
{
  return (p1 *= p2);
}

template<typename P1, typename P2>
P1 &dividesequal(P1 &p1, const P2 &p2)
{
  return (p1 /= p2);
}

template<typename P1, typename P2>
P1 &addsequal(P1 &p1, const P2 &p2)
{
  return (p1 += p2);
}

template<typename P1, typename P2>
P1 &subtractsequal(P1 &p1, const P2 &p2)
{
  return (p1 -= p2);
}

template<typename P1>
P1 &prefixincrement(P1 &p1)
{
  return (++p1);
}

template<typename P1>
P1 &prefixdecrement(P1 &p1)
{
  return (--p1);
}

//Add canonical forms of operators
template<typename T>
void add_oper_equals(BoxedCPP_System &s)
{
  register_function(s, &equals<const T&, const T&>, "=");
}

template<typename T>
void add_oper_add(BoxedCPP_System &s)
{
  register_function(s, &add<T, const T&, const T&>, "+");
}

template<typename T>
void add_oper_subtract(BoxedCPP_System &s)
{
  register_function(s, &subtract<T, const T&, const T&>, "-");
}

template<typename T>
void add_oper_divide(BoxedCPP_System &s)
{
  register_function(s, &divide<T, const T&, const T&>, "-");
}

template<typename T>
void add_oper_multiply(BoxedCPP_System &s)
{
  register_function(s, &multiply<T, const T&, const T&>, "*");
}

template<typename T>
void add_oper_not_equals(BoxedCPP_System &s)
{
  register_function(s, &not_equals<const T&, const T&>, "!=");
}

template<typename T, typename U>
void add_oper_assign_overload(BoxedCPP_System &s)
{
  register_function(s, &assign<T,U>, "=");
}


template<typename T>
void add_oper_assign(BoxedCPP_System &s)
{
  register_function(s, &assign<T,T>, "=");
}

template<typename T>
void add_oper_less_than(BoxedCPP_System &s)
{
  register_function(s, &less_than<const T&, const T&>, "<");
}

template<typename T>
void add_oper_greater_than(BoxedCPP_System &s)
{
  register_function(s, &greater_than<const T&, const T&>, ">");
}

template<typename T>
void add_oper_less_than_equals(BoxedCPP_System &s)
{
  register_function(s, &less_than_equals<const T&, const T&>, "<=");
}

template<typename T>
void add_oper_greater_than_equals(BoxedCPP_System &s)
{
  register_function(s, &greater_than_equals<const T&, const T&>, ">=");
}


template<typename T, typename R>
void add_opers_comparison_overload(BoxedCPP_System &s)
{
  register_function(s, &equals<const T&, const R&>, "==");
  register_function(s, &not_equals<const T&, const R&>, "!=");
  register_function(s, &less_than<const T&, const R&>, "<");
  register_function(s, &greater_than<const T&, const R&>, ">");
  register_function(s, &less_than_equals<const T&, const R&>, "<=");
  register_function(s, &greater_than_equals<const T&, const R&>, ">=");
}

template<typename T>
void add_opers_comparison(BoxedCPP_System &s)
{
  add_opers_comparison_overload<T, T>(s);
}

template<typename Ret, typename T, typename R>
void add_opers_arithmetic_overload(BoxedCPP_System &s)
{
  register_function(s, &add<Ret, T, R>, "+");
  register_function(s, &subtract<Ret, T, R>, "-");
  register_function(s, &divide<Ret, T, R>, "/");
  register_function(s, &multiply<Ret, T, R>, "*");
  register_function(s, &timesequal<T, R>, "*=");
  register_function(s, &dividesequal<T, R>, "/=");
  register_function(s, &subtractsequal<T, R>, "-=");
  register_function(s, &addsequal<T, R>, "+=");
  register_function(s, &prefixincrement<T>, "++");
  register_function(s, &prefixdecrement<T>, "--");
}

template<typename T>
void add_basic_constructors(BoxedCPP_System &s, const std::string &type)
{
  s.register_function(build_constructor<T>(), type);
  s.register_function(build_constructor<T, const T &>(), type);
}

template<typename T, typename U>
void add_constructor_overload(BoxedCPP_System &s, const std::string &type)
{
  s.register_function(build_constructor<T, const U &>(), type);
}

template<typename T>
void add_opers_arithmetic(BoxedCPP_System &s)
{
  add_opers_arithmetic_overload<T, T, T>(s);
}

//Built in to_string operator
template<typename Input>
std::string to_string(Input i)
{
  return boost::lexical_cast<std::string>(i);
}

std::string to_string(bool b)
{
  if (b)
  {
    return "true";
  } else {
    return "false";
  }
}

template<typename T, typename P1, typename P2, typename P3>
void bootstrap_pod_type(BoxedCPP_System &s, const std::string &name)
{
  s.register_type<T>(name);
  add_basic_constructors<T>(s, name);
  add_oper_assign<T>(s);
  add_opers_arithmetic<T>(s);
  add_opers_comparison<T>(s);
  register_function(s, &to_string<T>, "to_string");

  add_constructor_overload<T, P1>(s, name);
  add_constructor_overload<T, P2>(s, name);
  add_constructor_overload<T, P3>(s, name);

  /*
  add_opers_comparison_overload<T, P1>(s);
  add_opers_comparison_overload<T, P2>(s);
  add_opers_comparison_overload<T, P3>(s);
  */
}

void bootstrap(BoxedCPP_System &s)
{
  s.register_type<void>("void");

  s.register_type<std::string>("string");

  add_basic_constructors<double>(s, "double");
  add_basic_constructors<int>(s, "int");
  add_basic_constructors<char>(s, "char");
  add_basic_constructors<bool>(s, "bool");
  add_basic_constructors<std::string>(s, "string");
  add_oper_assign<std::string>(s);
  register_function(s, &to_string<const std::string &>, "to_string");


  bootstrap_pod_type<double, int, size_t, char>(s, "double");
  bootstrap_pod_type<int, double, size_t, char>(s, "int");
  bootstrap_pod_type<size_t, int, double, char>(s, "size_t");
  bootstrap_pod_type<char, int, double, size_t>(s, "char");


  add_opers_arithmetic_overload<double, int, double>(s);
  add_opers_arithmetic_overload<double, double, int>(s);

  add_opers_arithmetic_overload<double, size_t, double>(s);
  add_opers_arithmetic_overload<double, double, size_t>(s);

  add_opers_comparison_overload<int, double>(s);
  add_opers_comparison_overload<double, int>(s);


  add_oper_add<std::string>(s);

  register_function(s, &bool_and<bool, bool>, "&&");
  register_function(s, &bool_or<bool, bool>, "||");

}

#endif