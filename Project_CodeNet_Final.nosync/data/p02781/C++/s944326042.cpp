#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back 
#define eb emplace_back
#define fn for(int i =0 ;i <n;i++)
#define fn1 for( int i =1;i<=n;i++)
#define fm for(int j =0 ;j <m;j++)
#define fm1 for(int j =1;j<=m;j++)
#define fi first
#define se second
#define E endl
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
const int N = 2e6+5;
const int INF = 1e18L;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
int ar[N];
vector<int>v;
int dp[102][4][2]; // dp[pos][k][flag];
int solve(int pos, int cnt , int f , int k ,int n){
	if(pos==n){
		return cnt == k;
	}
	if(cnt > k)return 0;
	if(dp[pos][cnt][f]!=-1)return dp[pos][cnt][f];
	int limit = (f==0 ? v[pos] : 9);
	int ans =0 ;
	for(int i =0 ;i<=limit;i++){
		int curCnt =cnt;
		if(i!=0)curCnt++;
		int nf = f;
		if(i < limit && f==0)nf =1;
		ans+=solve(pos+1,curCnt,nf,k,n);
	}
	return dp[pos][cnt][f]=ans;
}
signed main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS;
	int T=1;
	// cin >> T;
	while(T--){
		int k;
		string s;
		cin>>s>>k;
		memset(dp,-1,sizeof(dp));
		for(char x : s)v.pb(x-'0');
		int n = s.size();
		int ans = solve(0,0,0,k,n);
		cout << ans<<endl;
	
	}
	cerr << "Time Taken : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}