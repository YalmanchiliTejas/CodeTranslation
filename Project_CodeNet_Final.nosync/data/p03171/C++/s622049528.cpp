#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9+7;
const double EPS = 1e-11;
const double PI = 2 * acos(0.0);
using ll = long long;
using ull =  unsigned long long;

#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define fast_io ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#define pf printf
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define sll(x,y) scanf("%lld %lld",&x,&y)

#define pii pair<int,int>
#define nl '\n'
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define uniq(a) a.erase(unique(a.begin(), a.end()), a.end())
#define out(x) cout <<"#x = "<<x<<endl
#define outt(x,y) cout <<"# "<<x<<" "<<y<<endl
#define mem(array,value) memset(array,value,sizeof(array))

int n;
ll dp[3007][3007][3];
int a[3007];

ll solve(int i,int j,int player)
{
	if(i>j)return 0;
	if(dp[i][j][player]!=-1)return dp[i][j][player];
	ll ans;
	if(player==1){
		if(i==j){
			ans = a[i]+solve(i+1,j,2);
		}
		else{
			ll samne = a[i]+solve(i+1,j,2);
			ll pisone = a[j]+solve(i,j-1,2);
			ans = max(samne,pisone);
			dp[i][j][player]=ans;
		}
	}
	else {
		if(i==j){
			ans = -a[i]+solve(i+1,j,2);
		}
		else{
			ll samne = -a[i]+solve(i+1,j,1);
			ll pisone = -a[j]+solve(i,j-1,1);
			ans = min(samne,pisone);
			dp[i][j][player]=ans;
		}
	}
	return dp[i][j][player]=ans;
}
int main()
{
	fast_io
	mem(dp,-1);
	cin >>n;
	for(int i=0;i<n;i++)cin >>a[i];
		cout <<solve(0,n-1,1)<<endl;
	return 0;
}
