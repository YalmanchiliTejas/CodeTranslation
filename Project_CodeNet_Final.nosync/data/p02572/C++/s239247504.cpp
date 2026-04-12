/**
*    author:  Dooloper
*    created: 29.08.2020 21:04:09
**/

#pragma region Macros
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using ll = long long;

#define rep(i,n) for(int i = 0; i < (n); i++)
#define repn(i,n) for(int i = 1; i <= (n); i++)
#define pb push_back
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const double PI = acos(-1);
const int mod = 1000000007;
class mint {
   long long x;
public:
   mint(long long x=0) : x((x%mod+mod)%mod) {}
   mint operator-() const {
     return mint(-x);
   }
   mint& operator+=(const mint& a) {
       if ((x += a.x) >= mod) x -= mod;
       return *this;
   }
   mint& operator-=(const mint& a) {
       if ((x += mod-a.x) >= mod) x -= mod;
       return *this;
   }
   mint& operator*=(const  mint& a) {
       (x *= a.x) %= mod;
       return *this;
   }
   mint operator+(const mint& a) const {
       mint res(*this);
       return res+=a;
   }
   mint operator-(const mint& a) const {
       mint res(*this);
       return res-=a;
   }
   mint operator*(const mint& a) const {
       mint res(*this);
       return res*=a;
   }
   mint pow(ll t) const {
       if (!t) return 1;
       mint a = pow(t>>1);
       a *= a;
       return a;
   }
   // for prime mod
   mint inv() const {
       return pow(mod-2);
   }
   mint& operator/=(const mint& a) {
       return (*this) *= a.inv();
   }
   mint operator/(const mint& a) const {
       mint res(*this);
       return res/=a;
   }

   friend ostream& operator<<(ostream& os, const mint& m){
       os << m.x;
       return os;
   }
};
#pragma endregion

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  mint ans = 0;
  vector<mint> sum(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(i == 0) sum[0] = a[0];
    else{
      sum[i] = sum[i-1] + a[i];
    }
  }
  for(int i = 1; i < n; i++){
    ans += sum[i-1]*a[i];
  }
  cout << ans << endl;
  return 0;
}