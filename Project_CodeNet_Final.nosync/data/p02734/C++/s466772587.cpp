#include <bits/stdc++.h>
#define ld long double
#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
//#define M   1000000007 // 1e9 + 7
#define MAXN 3030
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
	
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);

}

const int M = 998244353;
int a[3010];
int dp[MAXN][MAXN][3];
int n,s;
int res=0;

int32_t main(){
	fastio;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	// t==0 -> nao definiu L nem R;
	// t==1 -> já definiu L;
	// t==2 -> ja definiu L e R;
	dp[0][0][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=s;j++){
			dp[i+1][j][0]=mod(dp[i+1][j][0] + dp[i][j][0],M);
			dp[i+1][j][1]=mod(dp[i+1][j][1] + dp[i][j][1]+dp[i][j][0],M);// oq já tinha mais define L agr
			dp[i+1][j][2]=mod(dp[i+1][j][2] + dp[i][j][2] + dp[i][j][1],M);// oq já tinha mais define R agr (L tava definido)
			if(j+a[i]<=s){
				dp[i+1][j+a[i]][1]=mod(dp[i+1][j+a[i]][1] + dp[i][j][0] + dp[i][j][1],M);
				dp[i+1][j+a[i]][2]=mod(dp[i+1][j+a[i]][2] + dp[i][j][0] + dp[i][j][1],M);
			}
		}
	}
	cout<<dp[n][s][2]<<endl;
}