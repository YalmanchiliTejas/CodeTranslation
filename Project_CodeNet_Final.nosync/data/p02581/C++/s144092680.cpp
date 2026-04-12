#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[2005];
int a[6005];
int dp[6005][6005];
int Max[6005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<3*n;i++){
        scanf("%d",&a[i]);
    }
    v[a[0]].pb(0);
    v[a[1]].pb(1);
    int ans=0,add=0;
    for(int i = 1;i<n;i++){
        //a[i*3-1],a[i*3],a[i*3+1];
        if(a[i*3-1]==a[i*3]&&a[i*3]==a[i*3+1]){
            add++;
            continue;
        }
        for(int j =i*3-1;j<=i*3+1;j++){
            for(int k=j+1;k<=i*3+1;k++){
                dp[j][k]=max(dp[j][k],ans);
                Max[k]=max(Max[k],dp[j][k]);
                Max[j]=max(Max[j],dp[j][k]);
            }
        }
        for(int j = 0;j<i*3-1;j++){
            for(int k=i*3-1;k<=i*3+1;k++){
                dp[j][k]=max(dp[j][k],Max[j]);
                Max[j]=max(Max[j],dp[j][k]);
                Max[k]=max(Max[k],dp[j][k]);
            }
        }
        for(int j=i*3-1;j<=i*3+1;j++){
            if(v[a[j]].size()>=2){
                int x=v[a[j]].back(),y=v[a[j]][v[a[j]].size()-2];
                int aa,bb;
                if(j!=i*3-1)aa=i*3-1;
                else aa=i*3;
                if(j==i*3+1)bb=i*3;
                else bb=i*3+1;
                dp[aa][bb]=max(dp[aa][bb],dp[y][x]+1);
             //   printf("!%d %d %d\n",aa,bb,dp[aa][bb]);
                ans=max(ans,dp[aa][bb]);
                Max[aa]=max(Max[aa],dp[aa][bb]);
                Max[bb]=max(Max[bb],dp[aa][bb]);
            }
            for(int k=j+1;k<=i*3+1;k++){
                if(a[j]==a[k]&&v[a[j]].size()){
                    int x=v[a[j]].back();
                    int aa;
                    for(int b=i*3-1;b<=i*3+1;b++){
                        if(b!=k&&b!=j)aa=b;
                    }
                    for(int b=0;b<3*i-1;b++){
                        if(b==x)continue;
                        int xx=x,yy=b;
                        int res;
                        if(xx>yy){
                            dp[b][aa]=max(dp[b][aa],dp[yy][xx]+1);//query(yy,xx)+1;
                        }
                        else{
                            dp[b][aa]=max(dp[b][aa],dp[xx][yy]+1);
                        }
                        ans=max(ans,dp[b][aa]);
                    //    printf("?%d %d %d\n",b,aa,dp[b][aa]);
                        Max[b]=max(Max[b],dp[b][aa]);
                        Max[aa]=max(Max[aa],dp[b][aa]);
                    } 
                }  
            }
        }
       // printf("%d\n",ans);
        v[a[i*3-1]].pb(i*3-1);
        v[a[i*3]].pb(i*3);
        v[a[i*3+1]].pb(i*3+1);
    }
  /*  for(int i = 0;i<3*n-1;i++){
        for(int j = 0;j<3*n-1;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    if(v[a[3*n-1]].size()>=2){
        int x=v[a[3*n-1]].back(),y=v[a[3*n-1]][v[a[3*n-1]].size()-2];
      //  printf("%d %d\n",y,x);
        int res=dp[y][x]+1;
       // update(i,i,res); 
        ans=max(ans,res);
    }
    printf("%d\n",ans+add);
}
int main()
{
    int t=1;
    //scanf("%d",&t);
    int T=1;
    while(t--){
        solve();
    }
}