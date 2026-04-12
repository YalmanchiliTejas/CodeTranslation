#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#define ll long long
#define ull unsigned long long
#define IO ios::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define pi acos(-1)
#define lowbit(x) ((x)&(-(x)))
#define debug(x) cout<<x<<'\n'
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define RFOR(a,b,c) for(int a=b;a>=c;a--)
#define debug(x) cout<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define ls(x) x.resize(unique(all(x)) - x.begin())
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<double,double> Pd;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const double eps = 1e-10;
ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
ll mul(ll a,ll b){ll ans=0;a%=mod,b%=mod;while(b) { if(b&1) ans = (ans+a)%mod; a = (a*2)%mod; b >>= 1; }return ans;}
ll powmod(ll a,ll b){ll ans = 1;a %= mod;b%=(mod-1);while(b){if(b & 1){ans = ans * a % mod;b--;}b >>= 1;a = a * a % mod;}return ans;}
//(b/a)%p=b*a^(p-2)%p
int pr(ll num){if(num == 1) return 0;if(num ==2|| num==3 ) return 1 ;if(num %6!= 1&&num %6!= 5) return 0 ;int tmp =sqrt( num);for(int i= 5;i <=tmp; i+=6 )if(num %i== 0||num %(i+ 2)==0 )return 0 ;return 1 ;}
int Day(int y,int m, int d){if(m==1||m==2) { m+=12; y--; }int w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;return w+1;}
ll C(ll n,ll m) {if(n < m) return 0;ll res = 1;for(int i=1; i<=m; i++) {ll a = (n+i-m)%mod;ll b = i%mod;res = res*(a*powmod(b,mod-2)%mod)%mod;}return res;}
ll Lucas(ll n,ll m) {if(m == 0) return 1;return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;}
ll PRIMES[223] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409};
//const int maxn=2e7+5;
//ll v[maxn] = {0}, prime[maxn], Cnt = 0;
//void getpri(ll n) {for (ll i = 2; i <= n; ++i) {if (!v[i]) { v[i] = i; prime[++Cnt] = i;}for (ll j = 1; j <= Cnt; ++j) {if (prime[j] > v[i] || prime[j] * i > n) break; v[i * prime[j]] = prime[j];}}}
const int maxn = 1e6 + 5;
int a[maxn];
int main(){
  IO;
  int n;
  cin >> n;
  ll sum = 0;
  FOR(i,1,n){
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }
  ll ans = 0;
  FOR(i,1,n){
    sum -= a[i];
    sum += mod;
    sum %= mod;
    ans += sum * a[i];
    ans %= mod;
  }
  cout << ans << endl;

  return 0;
}