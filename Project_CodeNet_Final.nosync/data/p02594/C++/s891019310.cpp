#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define pb  push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLr(obj) (obj).rbegin(), (obj).rend()
#define endl "\n"
#define F first
#define S second
#define EN cout<<endl;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<P> VP;
typedef priority_queue<ll> PQ;
const ll mod=1000000007;
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yes(T b){if(b)out("yes");else out("no");}
template<class T> void Yes(T b){if(b)out("Yes");else out("No");}
template<class T> void YES(T b){if(b)out("YES");else out("NO");}
template<class T> void no(T b){if(b)out("no");else out("yes");}
template<class T> void No(T b){if(b)out("No");else out("Yes");}
template<class T> void NO(T b){if(b)out("NO");else out("YES");}
template<class T> int sint(T s){int n;sscanf(s.c_str(),"%d",&n);return n;}
//combsort
template<typename T> void cSort(vector<T>& v){size_t h = (v.size()*10)/13;bool is_sorted = false;while(!is_sorted){if(h==1)is_sorted = true;for(size_t i=0; i<v.size()-h; ++i){if(v[i]>v[i+h]){swap(v[i],v[i+h]);if(is_sorted)is_sorted = false;}}if(h>1) h = (h*10)/13;if(h==0) h = 1;}}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
template <int MOD>
struct ModInt {int val;ModInt(ll v = 0) : val(v % MOD) {if (val < 0) val += MOD;};ModInt operator+() const { return ModInt(val); }ModInt operator-() const { return ModInt(MOD - val); }ModInt inv() const { return this->pow(MOD - 2); }ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }ModInt pow(ll n) const {auto x = ModInt(1);auto b = *this;while (n > 0) {if (n & 1) x *= b;n >>= 1;b *= b;}return x;}ModInt& operator+=(const ModInt& x) {if ((val += x.val) >= MOD) val -= MOD;return *this;}ModInt& operator-=(const ModInt& x) {if ((val -= x.val) < 0) val += MOD;return *this;}ModInt& operator*=(const ModInt& x) {val = ll(val) * x.val % MOD;return *this;}ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }bool operator==(const ModInt& b) const { return val == b.val; }bool operator!=(const ModInt& b) const { return val != b.val; }friend istream& operator>>(istream& is, ModInt& x) noexcept { return is >> x.val; }friend ostream& operator<<(ostream& os, const ModInt& x) noexcept { return os << x.val; }};
constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;


int main(){
    FAST;
    ll n,d;
    string s;
    cin>>n;
    Yes(n>=30);

}