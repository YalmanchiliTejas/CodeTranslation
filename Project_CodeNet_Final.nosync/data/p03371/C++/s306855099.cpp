#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end());
#define VREV(v) reverse(v.begin(), v.end());
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vdouble = vector<double>;
using vstr = vector<string>;
typedef pair<int,int> P;
int dx[4] = {1, 0, -1, 0},dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
template<class T> inline bool chmax(T& a, T b){if(a<b) {a=b; return 1;} return 0; }
template<class T> inline bool chmin(T& a, T b){if(a>b) {a=b; return 1;} return 0; }
const ll INF = 1LL << 60;
const ll mod = 1000000007;

//ll dp[3100][3100];// dp[i][j]=
int keta10(ll n){
	return log10(n)+1;
}
int main(){
	ll A,B,AB,X,Y;
	cin>>A>>B>>AB>>X>>Y;
	ll ans=INF;
	for(ll ab=200200;0<=ab;ab-=2){
		ll a=max((ll)0,X-(ab/2));//追加で必要なAの数
		ll b=max((ll)0,Y-(ab/2));//追加で必要なBの数
		ans=min(ans,AB*ab+A*a+B*b);
	}
	cout<<ans<<endl;
}