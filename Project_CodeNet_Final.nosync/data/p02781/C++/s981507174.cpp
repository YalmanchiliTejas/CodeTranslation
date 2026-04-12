#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

string s;
ll dp[2][5][105];
int n,k;

int main(){
	cin>>s; n = s.size(); cin>>k;
	dp[0][0][0] = 1;
	rep(i,n){
		int nxt = s[i]-'0';
		rep(k,4){
			//dp[0][k][i]
			rep(j,nxt+1){
				dp[j!=nxt][k+!!j][i+1] += dp[0][k][i];
			}
			//dp[1][k][i]
			rep(j,10){
				dp[1][k+!!j][i+1] += dp[1][k][i];
			}
		}
	}
	cout<<(dp[0][k][n]+dp[1][k][n])<<endl;
}