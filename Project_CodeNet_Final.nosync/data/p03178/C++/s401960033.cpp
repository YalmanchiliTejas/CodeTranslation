#include <bits/stdc++.h>
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
string str;
int d;
ll dp[10005][105][2];
int main(){
	cin>>str;
	cin>>d;
	dp[0][0][0] = 1;
	for(int i=0;i<str.size();i++){
		int pos = str[i]-'0';
		for(int j=0;j<d;j++){
			for(int a=0;a<=pos;a++){
				if(a == pos) dp[i+1][(j+a)%d][0] += dp[i][j][0];
				else dp[i+1][(j+a)%d][1] += dp[i][j][0];
			}
			for(int a=0;a<=9;a++){
				dp[i+1][(j+a)%d][1] += dp[i][j][1];
			}
		}
		rep(j,d)rep(k,2)dp[i+1][j][k]%=mod;
	}
	ll ans = -1LL+dp[str.size()][0][0]+dp[str.size()][0][1];
	cout<<(ans%mod+mod)%mod<<endl;
}