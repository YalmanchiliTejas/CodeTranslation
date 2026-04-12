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

ll a[3000],dp[3001][3001];
int main(){
	int n; cin>>n;
	FOR(i,0,n) cin>>a[i];
	FOR(i,1,n+1){
		FOR(j,0,n-i+1){
			if(i==1){
				dp[j][j+i]=a[j];
			}else{
				dp[j][j+i]=max(a[j]-dp[j+1][j+i],a[i+j-1]-dp[j][j+i-1]);
			}
		}
	}
	co(dp[0][n]);
}
