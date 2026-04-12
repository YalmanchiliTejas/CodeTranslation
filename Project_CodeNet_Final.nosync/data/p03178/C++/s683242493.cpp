#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;

ll dp[10001][100];
int main(){
	string k;
	int d;
	cin>>k>>d;
	dp[0][0]=1;
	int sum=0;
	FOR(i,0,k.size()){
		FOR(j,0,d){
			FOR(jj,0,10){
				(dp[i+1][(j+jj)%d]+=dp[i][j])%=MOD;
			}
		}	
	}
	ll ans=0;
	FOR(i,0,k.size()){
		int dgt=k[i]-'0';
		FOR(j,0,dgt){
			ans+=dp[k.size()-1-i][(d*1000000-sum-j)%d];
			ans%=MOD;
		}
		sum+=dgt;
	}
	if(sum%d) (ans+=(MOD-1))%=MOD;
	co(ans);
	
}
