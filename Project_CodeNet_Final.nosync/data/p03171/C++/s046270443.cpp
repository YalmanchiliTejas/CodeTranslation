#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
long long arr[3005];
long long memo[3005][3005];
long long dp(int i,int j, bool k){
    if (i==j) return k?arr[i]:-arr[i];
    if (memo[i][j]!=-1) return memo[i][j];
    if (k){
        return memo[i][j]=max(arr[i]+dp(i+1,j,!k),arr[j]+dp(i,j-1,!k));
    }
    else{
        return memo[i][j]=min(-arr[i]+dp(i+1,j,!k),-arr[j]+dp(i,j-1,!k));
    }
}
int main(){
    memset(memo,-1,sizeof(memo));
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%lld",&arr[x]);
    }
    printf("%lld\n",dp(0,n-1,true));
}
