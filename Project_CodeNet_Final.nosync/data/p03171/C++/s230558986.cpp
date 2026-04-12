#include <bits/stdc++.h>
#ifdef PRAGMA
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#define fst first
#define snd second
#define fore(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define bs binary_search
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int) (n).size())
#define MAXI ((ll)1e16)
#define MINI ((ll)-1e16)
using namespace std;
typedef long long ll;  
     
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }          
ll n,res,aux;
ll a[3001];
ll dp[3001][3001][2];
ll solve(int l, int r, int k){
	if(l>r)return 0;
	if(dp[l][r][k]!=-1)return dp[l][r][k];
	if(!k)dp[l][r][k]=max(a[l]+solve(l+1,r,(k+1)%2),a[r]+solve(l,r-1,(k+1)%2));
	else dp[l][r][k]=min(solve(l+1,r,(k+1)%2)-a[l],solve(l,r-1,(k+1)%2)-a[r]);
	return dp[l][r][k];
}
int main(){FIN;
	cin >> n;
	fore(i,0,n){
		cin >> a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << solve(0,n-1,0);
	
}