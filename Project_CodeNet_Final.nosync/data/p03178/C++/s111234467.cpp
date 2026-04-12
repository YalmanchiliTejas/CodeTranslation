#include <bits/stdc++.h>
#define int long long int
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;

struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

template<int mod=MOD>
struct ModRing {
   int x;
   ModRing() : x(0) {}
   ModRing(int a) { x = ((a % mod) + mod) % mod; }

   bool operator==(const ModRing& a) const {
      return x == a.x;
   }
   bool operator!=(const ModRing& a) const {
      return x != a.x;
   }
   bool operator==(int a) const {
      return *this == ModRing(a);
   }
   bool operator!=(int a) const {
      return *this != ModRing(a);
   }
   ModRing& operator=(int a) {
      return *this = ModRing(a);
   }
   ModRing operator-() const {
      return ModRing((-x + mod) % mod);
   }
   ModRing& operator+=(const ModRing& a) {
      (x += a.x) %= mod;
      return *this;
   }
   ModRing& operator-=(const ModRing& a) {
      return *this += -a;
   }
   ModRing& operator*=(const ModRing& a) {
      (x *= a.x) %= mod;
      return *this;
   }
   const ModRing operator+(const ModRing& a) const {
      return ModRing(x) += a;
   }
   const ModRing operator-(const ModRing& a) const {
      return ModRing(x) -= a;
   }
   const ModRing operator*(const ModRing& a) const {
      return ModRing(x) *= a;
   }
   ModRing& operator+=(int a) {
      return *this += ModRing(a);
   }
   ModRing& operator-=(int a) {
      return *this -= ModRing(a);
   }
   ModRing& operator*=(int a) {
      return *this *= ModRing(a);
   }
   const ModRing operator+(int a) const {
      return ModRing(x) += a;
   }
   const ModRing operator-(int a) const {
      return ModRing(x) -= a;
   }
   const ModRing operator*(int a) const {
      return ModRing(x) *= a;
   }
   ModRing power(int n) const {
      ModRing tmp(x), res(1);
      while (n > 0) {
         if ((n & 1) == 1) res *= tmp;
         tmp *= tmp;
         n >>= 1;
      }
      return res;
   }
};
template<int mod>auto&operator<<(ostream&s,const ModRing<mod>&a){s<<a.x;return s;}

template<int mod=MOD>
struct FiniteField : ModRing<mod> {
   FiniteField() : ModRing<mod>() {}
   FiniteField(int a) : ModRing<mod>(a) {}
   FiniteField(const ModRing<mod>& a) : ModRing<mod>(a) {}

   FiniteField& operator=(int a) {
      return *this = ModRing<mod>::operator=(a);
   }
   FiniteField& operator+=(const FiniteField& a) {
      return *this = ModRing<mod>::operator+=(a);
   }
   FiniteField& operator-=(const FiniteField& a) {
      return *this = ModRing<mod>::operator-=(a);
   }
   FiniteField& operator*=(const FiniteField& a) {
      return *this = ModRing<mod>::operator*=(a);
   }
   FiniteField& operator+=(int a) {
      return *this = ModRing<mod>::operator+=(a);
   }
   FiniteField& operator-=(int a) {
      return *this = ModRing<mod>::operator-=(a);
   }
   FiniteField& operator*=(int a) {
      return *this = ModRing<mod>::operator*=(a);
   }

   FiniteField inverse() const {
      try { if (this->x == 0) throw "0 have no inverse"; }
      catch (const char* e) { cerr << e << endl; }
      return ModRing<mod>::power(mod-2);
   }
   FiniteField& operator/=(const FiniteField& a) {
      return *this *= a.inverse();
   }
   const FiniteField operator/(const FiniteField& a) const {
      return FiniteField(*this) /= a;
   }
   FiniteField& operator/=(int a) {
      return *this /= FiniteField(a);
   }
   const FiniteField operator/(int a) const {
      return FiniteField(*this) /= a;
   }
};

signed main()
{
   string S; cin >> S;
   int D; cin >> D;

   int K = S.size();

   using GF = FiniteField<>;

   V<V<GF>> dp(K, V<GF>(D));
   dp[0][0] = 1;
   for (int k = 0; k < K-1; k++) {
      for (int i = 0; i < D; i++) {
         for (int j = 0; j < 10; j++) {
            dp[k+1][(i+j) % D] += dp[k][i];
         }
      }
   }

   V<int> sum(K+1);
   for (int k = 0; k < K; k++) {
      sum[k+1] = (sum[k] + (S[k]-'0')) % D;
   }

   GF ans = 0;
   for (int k = 0; k < K; k++) {
      for (int i = 0; i < S[k]-'0'; i++) {
         int d = (sum[k] + i) % D;
         d = (-d + D) % D;
         ans += dp[K-1-k][d];
      }
   }

   ans -= 1;
   if (sum[K] == 0) ans += 1;

   cout << ans << endl;

   return 0;
}
