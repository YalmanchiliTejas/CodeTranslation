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
#define INF 1000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
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

int n,m,k,ans;
string s;
int dp[111][2][111];//桁、未満フラグ、kのカウント
signed main(){
	 cin>>s>>k;
	 dp[0][0][0]=1;
	 rep(i,s.size()){
	 	int now=s[i]-'0';
	 	rep(smaller,2){
	 			rep(cnt,k+1){
	 				for(int x=0;x<=(smaller?9:now);x++){
	 					if(x==0)dp[i+1][smaller||x<now][cnt]+=dp[i][smaller][cnt];
	 					else dp[i+1][smaller||x<now][cnt+1]+=dp[i][smaller][cnt];
	 				}
	 			}
	 	}
	 }
	 cout<<dp[s.size()][0][k]+dp[s.size()][1][k]<<endl;
}
