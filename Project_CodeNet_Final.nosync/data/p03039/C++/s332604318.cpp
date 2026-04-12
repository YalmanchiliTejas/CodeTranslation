#include <bits/stdc++.h>
using namespace std;
using LL = long long;

template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}


// std::vector Declaration
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts) {
   return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

// std::vector Initialization
template<typename T>
void fill_all(T& arr, const T& v) { arr = v; }
template<typename T, typename U>
void fill_all(T& arr, const U& v) { for (auto& i : arr) fill_all(i, v); }

// std::vector Debug
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
   os << "[";
   bool a = 1;
   for (auto e : v ) {
      os << (a ? "" : " "); 
      os << e;
      a = 0;
   }
   os << "]";
   return os;
}

// std::pair Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
   os << "(" << p.first << " " << p.second << ")";
   return os;
}

// std::set Debug
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
   os << "{";
   bool a = 1;
   for (auto e : st) {
      os << (a ? "" : " ");
      os << e;
      a = 0;
   }
   os << "}";
   return os;
}

// std::map Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
   os << "{";
   bool a = 1;
   for (auto e : mp) {
      os << (a ? "" : " ");
      os << e.first << ":" << e.second;
      a = 0;
   }
   os << "}";
   return os;
}

// std::tuple Debug
template<int N,class Tuple>
void out(ostream &os,const Tuple &t){}
template<int N,class Tuple,class H,class ...Ts>
void out(ostream &os,const Tuple &t){
   if(N)os<<" ";
   os<<get<N>(t);
   out<N+1,Tuple,Ts...>(os,t);
}
template<class ...Ts>
ostream& operator<<(ostream &os, const tuple<Ts...> &t){
   os<<"(";
   out<0,tuple<Ts...>,Ts...>(os,t);
   os<<")";
   return os;
}

// Debug
#define DUMP(x) cout<<#x<<" = "<<(x)<<endl

struct edge { int to, cost; };

const LL LINF = 1LL<<60;
const int IINF = 1<<30;
const LL MOD = 1e9+7;

template<typename Ring>
struct Fact {
   vector<Ring> fact;
   Fact(int n) {
      fact.resize(n+1);
      fact[0] = Ring::idMul();
      for (int i = 1; i <= n; ++i) {
         fact[i] = fact[i-1] * i;
      }
   }
   Ring operator[](int i) {
      return fact[i];
   }
};

template<typename Field>
struct Comb {
   Fact<Field> fact;
   Comb(int n) : fact(n) {}
   Field operator()(int n, int r) {
      if (n < 0 || n-r < 0 || r < 0) {
         return 0;
      }
      return fact[n] / (fact[n-r] * fact[r]);
   }
};


template<typename Type, typename Operators>
struct AlgStruct {

   Type x;

   template<typename... Args> AlgStruct(Args... args) : x(args...) {}

   template<typename... Args>
      decltype(auto) operator[](Args... args) { return x.operator[](args...); }


   AlgStruct& operator=(const AlgStruct& value) & = default;

   template<typename... Args>
      static const AlgStruct idAdd(Args... args) { return Operators::IdAdd(args...); }

   template<typename... Args>
      static const AlgStruct idMul(Args... args) { return Operators::IdMul(args...); }

   const AlgStruct operator+() const { return *this; }
   const AlgStruct operator-() const { return Operators::Opposite(x); }
   const AlgStruct reciprocal() const { return Operators::Reciprocal(x); }

   AlgStruct& operator+=(const AlgStruct& rhs) { x = Operators::Add(x, rhs.x); return *this; }
   AlgStruct& operator-=(const AlgStruct& rhs) { *this += -rhs; return *this; }
   AlgStruct& operator*=(const AlgStruct& rhs) { x = Operators::Mul(x, rhs.x); return *this; }
   AlgStruct& operator/=(const AlgStruct& rhs) { return *this *= rhs.reciprocal(); }

   const AlgStruct operator+(const AlgStruct& rhs) const { return AlgStruct(*this) += rhs; }
   const AlgStruct operator-(const AlgStruct& rhs) const { return AlgStruct(*this) -= rhs; }
   const AlgStruct operator*(const AlgStruct& rhs) const { return AlgStruct(*this) *= rhs; }
   const AlgStruct operator/(const AlgStruct& rhs) const { return AlgStruct(*this) /= rhs; }

   const AlgStruct power(long long n) const { return Operators::Power(x, n); }

   bool operator<(const AlgStruct& rhs) const { return Operators::Less(x, rhs.x); }
   bool operator>(const AlgStruct& rhs) const { return rhs < *this; }
   bool operator<=(const AlgStruct& rhs) const { return !(*this > rhs); }
   bool operator>=(const AlgStruct& rhs) const { return !(*this < rhs); }
   bool operator==(const AlgStruct& rhs) const { return !(*this < rhs) && !(*this > rhs); }
   bool operator!=(const AlgStruct& rhs) const { return !(*this == rhs); }
};

template<typename Type, typename Operators>
const AlgStruct<Type, Operators> operator+(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) + rhs;
}
template<typename Type, typename Operators>
const AlgStruct<Type, Operators> operator-(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) - rhs;
}
template<typename Type, typename Operators>
const AlgStruct<Type, Operators> operator*(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) * rhs;
}
template<typename Type, typename Operators>
const AlgStruct<Type, Operators> operator/(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) / rhs;
}

template<typename Type, typename Operators>
bool operator<(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) < rhs;
}
template<typename Type, typename Operators>
bool operator>(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) > rhs;
}
template<typename Type, typename Operators>
bool operator<=(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) <= rhs;
}
template<typename Type, typename Operators>
bool operator>=(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) >= rhs;
}
template<typename Type, typename Operators>
bool operator==(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) == rhs;
}
template<typename Type, typename Operators>
bool operator!=(const Type& lhs, const AlgStruct<Type, Operators>& rhs) {
   return AlgStruct<Type, Operators>(lhs) != rhs;
}

template<typename Type, typename Operators>
auto& operator<<(ostream& s,const AlgStruct<Type, Operators>& value){ s << value.x; return s; }


template<typename T, T mod>
struct GaloisFieldOperators {
   static T Add(T lhs, T rhs) { return (lhs + rhs) % mod; };
   static T Mul(T lhs, T rhs) { return (lhs * rhs) % mod; };
   static T IdAdd() { return 0; };
   static T IdMul() { return 1; };
   static T Opposite(T value) { return ((-value % mod) + mod) % mod; };
   static bool Less(T lhs, T rhs) { return lhs < rhs; };
   static T Power(T value, long long n) {
      T res = IdMul();
      while (n > 0) {
         if (n & 1) res = Mul(res, value);
         value = Mul(value, value); n >>= 1;
      }
      return res;
   }
   static T Reciprocal(T value) { return Power(value, mod-2); }
};

using GaloisField = AlgStruct<long long, GaloisFieldOperators<long long, MOD>>;

int main()
{
   LL n, m; cin >> n >> m;
   LL k; cin >> k;

   Comb<GaloisField> comb(n*m);

   GaloisField total = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         total += (GaloisField(i-1)*i/2 + GaloisField(n-i)*(n-i+1)/2) * m;
         total += (GaloisField(j-1)*j/2 + GaloisField(m-j)*(m-j+1)/2) * n;
      }
   }

   GaloisField ans = total * comb(n*m-2, k-2) / 2;
   cout << ans << endl;


   return 0;
}
