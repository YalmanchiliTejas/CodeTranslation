#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using f32 = float;
using f64 = double;
using i64 = int64_t; 
using u64 = uint64_t; 

#define SELECTER(_1, _2, _3, _4, _5, _6, _7, _8, SELECT, ...) SELECT

#define _FC1(func, type, _1)      func(type, _1) 
#define _FC2(func, type, _1, ...) func(type, _1); _FC1(func, type, __VA_ARGS__)
#define _FC3(func, type, _1, ...) func(type, _1); _FC2(func, type, __VA_ARGS__) 
#define _FC4(func, type, _1, ...) func(type, _1); _FC3(func, type, __VA_ARGS__)
#define _FC5(func, type, _1, ...) func(type, _1); _FC4(func, type, __VA_ARGS__)
#define _FC6(func, type, _1, ...) func(type, _1); _FC5(func, type, __VA_ARGS__)
#define _FC7(func, type, _1, ...) func(type, _1); _FC6(func, type, __VA_ARGS__)
#define _FC8(func, type, _1, ...) func(type, _1); _FC7(func, type, __VA_ARGS__)

#define _FCN(func, type, ...) SELECTER(__VA_ARGS__, _FC8, _FC7, _FC6, _FC5, _FC4, _FC3, _FC2, _FC1)(func, type, __VA_ARGS__)

constexpr const char *type2fmt(const char *fmt) {
  if(strcmp(fmt, "i32") == 0) return "%d";
  if(strcmp(fmt, "u32") == 0) return "%u";
  if(strcmp(fmt, "f32") == 0) return "%f";
  if(strcmp(fmt, "f64") == 0) return "%lf";
  if(strcmp(fmt, "i64") == 0) return "%lld";
  if(strcmp(fmt, "u64") == 0) return "%llu";
  return "";
}

#define _R(type, _1) type _1; { type _t; scanf(type2fmt(#type), &_t); _1 = _t; }
#define _P(type, _1) { const type _t = (_1); printf(type2fmt(#type), _t); putchar('\n'); }

#define RI(...)   _FCN(_R, i32, __VA_ARGS__)
#define RUI(...)  _FCN(_R, u32, __VA_ARGS__)
#define RF(...)   _FCN(_R, f32, __VA_ARGS__)
#define RD(...)   _FCN(_R, f64, __VA_ARGS__)
#define RLL(...)  _FCN(_R, i64, __VA_ARGS__)
#define RULL(...) _FCN(_R, u64, __VA_ARGS__)

#define PI(...)   _FCN(_P, i32, __VA_ARGS__)
#define PUI(...)  _FCN(_P, u32, __VA_ARGS__)
#define PF(...)   _FCN(_P, f32, __VA_ARGS__)
#define PD(...)   _FCN(_P, f64, __VA_ARGS__)
#define PLL(...)  _FCN(_P, i64, __VA_ARGS__)
#define PULL(...) _FCN(_P, u64, __VA_ARGS__)

#define REP(n) for (int _i = 0; _i < n; _i++)

const u64 mod = 1000000007;

int main() {
  RULL(X);
  if (X == 7 || X == 5 || X == 3) cout << "YES" << endl;
  else cout << "NO" << endl;
}
