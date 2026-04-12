#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast") 
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
#define endl '\n'
# define PI  3.14159265358979323846
#define MOD 1000000007
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
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
int dp[10010][100][2];
inline int add(int x, int y, int mod) {
   if (y >= mod) y %= mod;
   if (x >= mod) x %= mod;
   x  += y;
   return (x >= mod ? x - mod : x);
} 
inline int mul(int x, int y, int mod) {
  if (x >= mod) x %= mod;
  if (y >= mod) y %= mod;
  return (x*y) % mod;
}
inline int sub(int x, int y, int mod) {
  x -= y;
  if (x + mod <= 0) {
	x %= mod;
  }
  return (x < 0 ? x+mod : x);
}
vector<int>v;
int k;
int solve(int pos ,int curMod , int f , int n){
	if(pos==n){
		return curMod==0;
	}
	if(dp[pos][curMod][f]!=-1)return dp[pos][curMod][f];
	int lim = (f==0 ? v[pos] : 9);
	int ans =0 ;
	for(int i =0 ;i<=lim;i++){
		int nf=f;
		int newMod =0;
		newMod+=(curMod+i%k)%k;
		if(i < lim && !f)nf =1;
		ans =add(ans, solve(pos+1,newMod,nf,n),MOD);
	}
	return dp[pos][curMod][f]=ans;
}
int go(string &s){
	v.clear();
	memset(dp,-1,sizeof(dp));
	int n = s.size();
	for(auto i : s){
		v.pb(i-'0');
	}
	int ans = solve(0,0,0,n);
	ans = sub(ans,1,MOD);
	return ans;
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
		string s;
		cin >> s>> k;
		cout << go(s);
	
	}
	cerr << "Time Taken : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}