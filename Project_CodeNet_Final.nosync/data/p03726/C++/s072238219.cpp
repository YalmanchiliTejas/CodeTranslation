#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int dp[100005][2];
vector<int> v[100005];
void dfs(int x,int f){
    dp[x][1]=0;
    dp[x][0]=0;
    for(auto it:v[x]){
        if(it!=f){
        dfs(it,x);
        dp[x][0]=max(dp[x][0]+dp[it][0],dp[x][1]+dp[it][1]+1);
        dp[x][1]+=dp[it][0];
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    if(n%2==1){
        printf("First\n");
        return 0;
    }
    else{
        for(int i = 1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs(1,0);
        if(dp[1][0]==n/2){
            printf("Second\n");
        }
        else{
            printf("First\n");
        }
    }
}
/*
1-n 0
2-n 1
3-n 2
-3 0
-2 1
-1 2
0 3
*/
/*
1 0
2 -10  01
3 -20 -1 1 0 2


*/
/*

k*cnt[i]-k*cnt[j]=i-j;
k*cnt[i]-i=k*cnt[j]-j
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5    3
1 2 3 5 6    4 
1 2 3 4 6
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/