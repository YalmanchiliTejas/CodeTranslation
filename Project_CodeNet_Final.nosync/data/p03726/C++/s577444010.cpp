#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

vector<int> v[101010];
int n,dp[2][101010];
int dfs(int k,int x,int par){
    if(dp[x][k]!=0)return dp[x][k];
    int ret=0;
    if(x==1){
        ret=1;
        for(auto e:v[k])if(e!=par)ret+=min(dfs(e,1,k),dfs(e,0,k));
    }
    else for(auto e:v[k])if(e!=par)ret+=dfs(e,1,k);
    return dp[x][k]=ret;
}
int main(){
    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans=min(dfs(0,1,-1),dfs(0,0,-1));
    if(2*ans<n)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}