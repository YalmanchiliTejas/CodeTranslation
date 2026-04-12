#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i,ii,iii) for(ll i=ii;i<iii;i++)
#define mset(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define sz(a) (int)a.size()

const ll N=1e4+15,MOD=1e9+7;
string k;
ll d,n,dp[N][128][2],a[N];

ll solve(int p,int m,bool b) {
	if(p==n)return !m;
	if(dp[p][m][b]!=-1)return dp[p][m][b];\
	ll res=0;
	fore(i,0,a[p])res=(res+solve(p+1,(m+i)%d,1))%MOD;
	if(b) {
		fore(i,a[p],10)res=(res+solve(p+1,(m+i)%d,1))%MOD;
	} else {
		res=(res+solve(p+1,(m+a[p])%d,0))%MOD;
	}
	//cout<<p<<" "<<m<<" "<<b<<" : "<<res<<endl;
	return dp[p][m][b]=res;
}


int main() {
  ios::sync_with_stdio(false);
	mset(dp,-1);
	cin>>k>>d;n=k.length();
	fore(i,0,n)a[i]=k[i]-'0';
	cout<<(solve(0,0,0)+MOD-1)%MOD<<endl;
}