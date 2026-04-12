#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int N,M;
int dp[1<<8][10];
int edge[20][20];
 
int main(){
 
cin>>N>>M;
 
for(int i=0; i<M; i++){
    int a,b; scanf("%d %d",&a,&b); a--; b--;
    edge[a][b]++; edge[b][a]++;
}
 
dp[0][0]=1;
 
for(int i=0; i<(1<<N); i++){
    for(int v=0; v<N; v++){
        if(i>>v&1) continue;
        for(int u=0; u<N; u++){
      
                if(edge[u][v]) dp[i|(1<<v)][v]+=dp[i][u];
    
        }
    }
}
 
 int ans=0;
for(int i=0; i<N; i++) ans+=dp[(1<<N)-2][i];

cout<<ans<<endl;
 
}