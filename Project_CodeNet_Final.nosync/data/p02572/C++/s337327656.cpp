#line 1 "/home/parallels/kyopro/cplib/template.cpp"
#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a,T b){ if(a < b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a > b){ a = b; return true; }else return false; }

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;
using vpi = vector<Pi>;
using vpl = vector<Pl>;

void lyn(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

#line 1 "/home/parallels/kyopro/cplib/debug.cpp"
#define debug(arr) cout << #arr << " = " << arr << '\n'
#define debug2(a,b) cout << "[" << #a << "," << #b << "] = " << "[" << a << "," << b << "]" << '\n'
template<class T> ostream &operator << (ostream& out, const vector<T>& arr) {
	cout << "{"; for (int i = 0; i < arr.size(); i++)cout << (!i ? "" : ", ") << arr[i]; cout << "}";
	return out;
}
template<class T> ostream &operator << (ostream& out, const vector<vector<T> >& arr) {
	cout << "{\n"; for (auto& vec : arr)cout << "  " << vec << ",\n"; cout << "}";
	return out;
}
template<class S,class T> ostream &operator << (ostream& out, const pair<S,T>& p){
  cout << "{" << p.first << "," << p.second << "}" << '\n';
  return out;
}
template<class T> istream &operator >> (istream& in, vector<T>& arr) {
	for (auto& i : arr)cin >> i; return in;
}
#line 1 "/home/parallels/kyopro/cplib/modint.cpp"
template<int mod = 1000000007> struct modint{
  long long x; 
  modint(long long x=0):x((x%mod+mod)%mod){}
  modint operator-() const { return modint(-x);}
  modint& operator+=(const modint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
  modint& operator-=(const modint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
  modint& operator*=(const modint a) { (x *= a.x) %= mod; return *this;}
  modint operator+(const modint a) const { return modint(*this) += a;}
  modint operator-(const modint a) const { return modint(*this) -= a;}
  modint operator*(const modint a) const { return modint(*this) *= a;}
  modint pow(long long t) const {
    if (!t) return 1; modint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a;
  }
  // for prime mod
  modint inv() const { return pow(mod-2);}
  modint& operator/=(const modint a) { return *this *= a.inv();}
  modint operator/(const modint a) const { return modint(*this) /= a;}
};
template<int mod = 1000000007>
istream& operator>>(istream& is, modint<mod>& a) { return is >> a.x;}
template<int mod = 1000000007>
ostream& operator<<(ostream& os, const modint<mod>& a) { return os << a.x;}

#line 3 "main.cpp"
using mint = modint<(int)(1e9+7)>;
int main(int argc, char const* argv[])
{
  lyn();
  
  mint sum = 0;
  int n;cin >> n;
  vector<ll> a(n);
  cin >> a;

  vector<mint> cum(n+1,0);
  REP(i,n)cum[i+1] = cum[i] + a[i];

  mint ans = 0;

  REP(i,n){
    ans += (mint)a[i] * (cum[n] - cum[i+1]);
  }
  cout << ans << '\n';
  return 0;
}
