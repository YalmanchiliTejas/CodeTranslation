
// Problem : L - Deque
// Contest : Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_l
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(long long int i=0;i<n;i++)
#define FORR(i,n) for(long long int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<long long int>
#define slli set<long long int>
#define mlli map<long long int,long long int>
#define lli long long int 
#define test lli tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
using namespace std;
lli n, arr[3001],dp[3001][3001][2];
lli go(lli s,lli e,lli t){
	if(s>e) return 0;
	if(dp[s][e][t]!=-1) return dp[s][e][t]; 
	if(t==0){
		return dp[s][e][t]=max(arr[s]+go(s+1,e,1),arr[e]+go(s,e-1,1));
	}
		return dp[s][e][t]=min(-arr[s]+go(s+1,e,0),-arr[e]+go(s,e-1,0));
}


void solve(){
	cin>>n;
	FOR(i,n)cin>>arr[i];	
	cout<<go(0,n-1,0);
}


int32_t main() {
    	set(dp,-1);
    	solve();
    return 0;
}
