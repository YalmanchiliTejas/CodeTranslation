#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

int N,M;
vector<int>G[10];
long long dp[10000];
long long dfs(int v,long long x){
     //cout<<"v"<<v<<x<<endl;
     //if(dp[x]!=-1)return dp[x];
     if(x==((1<<N)-1))return 1;
     long long ans=0;
     REP(i,G[v].size()){
         int t=G[v][i];
         if(((x>>t)&1)==0){
            ans+=dfs(t,x|(1<<t));
         }
     }
     dp[x]=ans;
     return ans;
}

int main(){
        cin>>N>>M;
        REP(i,M){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        REP(i,10000){
            dp[i]=-1;
        }
        
        cout<<dfs(0,1)<<endl;
	return(0);
}