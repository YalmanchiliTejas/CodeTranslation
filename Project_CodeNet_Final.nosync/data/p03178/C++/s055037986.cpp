#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 2000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 0
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
using namespace std;
string k;
int n,m,ans;
int dp[11111][2][111];
signed main(){
	cin>>k>>m;
	n=k.size();
	dp[0][0][0]=1;
	rep(i,n){
		int num=k[i]-'0';
		rep(smaller,2){
			rep(j,m){
				for(int x=0;x<=(smaller?9:num);x++){
					dp[i+1][smaller||x<num][(j+x)%m]+=dp[i][smaller][j];
					dp[i+1][smaller||x<num][(j+x)%m]%=MOD;
				}
			}
		}
	}
	ans=dp[n][0][0]+dp[n][1][0];
	ans%=MOD;
	ans--;ans=(ans+MOD)%MOD;
	cout<<ans<<endl;
}
