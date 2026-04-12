#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
LL dp[10005][105];
int mod=1e9+7;
int main(){
    char c[100005];
    scanf("%s",c);
    int d;
    scanf("%d",&d);
    int sum=0;
    for(int i=0;c[i]!=0;i++){
        for(int j=0;j<c[i]-'0';j++){
            if(i==0&&j==0)continue;
                dp[i][(sum+j)%d]++;
        }
        sum+=c[i]-'0';
    }
    for(int i=1;c[i]!=0;i++){
        for(int j=1;j<=9;j++){
            dp[i][j%d]++;
        }
    }
    for(int i=0;c[i+1]!=0;i++){
        for(int j=0;j<d;j++){
            dp[i][j]%=mod;
            for(int k=0;k<10;k++){
                dp[i+1][(j+k)%d]+=dp[i][j];
            }
        }
    }
    printf("%d\n",(dp[strlen(c)-1][0]+(sum%d==0))%mod);
}
