/*/ Author: KaySeeKay /*/

#include<bits/stdc++.h>
using namespace std;	

/*/---------------------------Defines-----------------------------------------/*/

#pragma GCC optimize("Ofast") 
#define int long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back 
#define eb emplace_back
#define fn for(int i =0 ;i <n;i++)	
#define fn1 for( int i =1;i<=n;	i++)
#define fm for(int j =0 ;j <m;j++)
#define fm1 for(int j =1;j<=m;j++)
#define fi first
#define se second
#define endl '\n'
#define PI  3.14159265358979323846
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
int dp[N];
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
/*/-----------------------------Code begins----------------------------------/*/


signed main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS;
	int T=1;
	// cin >> T;
	while(T--){
		int n;
		cin >> n ;
		fn1{
			cin >> ar[i];
			dp[i]=dp[i-1]+ar[i];
		}
		int ans =0 ;
		fn1{
			int right = dp[n] - dp[i];
			int cur=right;
			cur=mul(cur,ar[i],MOD);
			ans=add(ans,cur,MOD);
		}
		cout <<ans;

	
	
	}
	return 0;
}