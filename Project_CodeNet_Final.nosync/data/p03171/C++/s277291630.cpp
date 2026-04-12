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

ll dp[3100][3100];// dp[i][j]=元の数列から連続する区間a[i],a[i+1],...,a[j-1]を抜き出した状態から最善を尽くした時のX-Yの値
int main(){
	ll N; cin>>N;
	vll a(N); rep(i,N) cin>>a[i];
	
	rep(i,N) dp[i][i]=0;
	
	for(ll i=1; i<=N; i++){//区間幅の長さ
		for(ll j=0; j+i<=N; j++){//先頭の番号
			ll k=i+j;//末尾の番号
			
			if((N-i)%2==0){
				dp[j][k]=max(dp[j+1][k]+a[j],dp[j][k-1]+a[k-1]);
			}
			else{
				dp[j][k]=min(dp[j+1][k]-a[j],dp[j][k-1]-a[k-1]);
			}
			
			
		}
	}
	
	cout<<dp[0][N]<<endl;
}