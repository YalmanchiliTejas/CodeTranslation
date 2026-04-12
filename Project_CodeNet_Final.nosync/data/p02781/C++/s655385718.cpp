#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy -2147382637
#define bql 2147483647
#define ll long long
#define ull unsigned long long
#define ld long double
#define il inline
#define sz(x) x.size()
#define maxn 100010
#define rp(i, l, r) for (int i = l; i <= r; i++)
#define rb(i, r, l) for (int i = r; i >= l; i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll min(ll a,ll b){if(a<b)return a;else return b;}
ll lowbit(ll x){return x&(-x);}
ll prime(ll x){
   if(x<=1)return false;
   for(int i=2;i<=int(sqrt(x));i++){
	   if(x%i==0)return false;
   }return true;
}bool cmp(ll a,ll b){return a>b;}
ll gcd(ll a,ll b){ll r;while(b>0){r=a%b;a=b;b=r;}return a;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int readint() {
	char c = getchar(); int w = 1; int x = 0;
	while (!isdigit(c))
		(c == '-') && (w = -w), c = getchar();
	while (isdigit(c))
		x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	x *= w;
	return x;
}
inline ll readll() {
	char c = getchar(); ll w = 1; ll x = 0;
	while (!isdigit(c))
		(c == '-') && (w = -w), c = getchar();
	while (isdigit(c))
		x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	x *= w;
	return x;
}
void fl(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
		  dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
#define MAXN 210
int k,n;
char a[MAXN];
int dp[110][5][2];
int dfs(int now,int cnt,bool limit){
	if(now==n+1)return cnt==k;
	if(cnt>k)return 0;
	if(dp[now][cnt][limit]>=0&&!limit)return dp[now][cnt][limit];
	int maxv=0;
	if(limit==1)maxv=a[now]-'0';
	else maxv=9;
	int ans=0;
	for(int i=0;i<=maxv;i++){
		ans+=dfs(now+1,cnt+(i!=0),limit&&(i==maxv));
	}
	return dp[now][cnt][limit]=ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>(a+1)>>k;
	n=strlen(a+1);
	cout<<dfs(1,0,1)<<endl;
}
/* stuff to remember
	* int overflow, array bounds
	* special cases (n=1? n=0?)
	* do something instead of nothing and stay organized
	* USE STATIC ARRAYS
	* DEFINING ARRAYS BEFORE main()
	* DO NOT DEFINE ARRAYS IN main()
	* USE INT INSTEAD OF LL,NOTICE THE MLE
*/