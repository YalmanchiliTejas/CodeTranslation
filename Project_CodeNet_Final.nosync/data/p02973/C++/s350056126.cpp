#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
const int inf=2e9;

int n=0;
int a[200005],inp;
int dp[200005];

int LIS(){
    int ln=0;dp[ln]=-inf;
    for(int i=1;i<=n;i++){
        if(a[i]>dp[ln]){
            dp[++ln]=a[i];
        }else{
            int idx=lower_bound(dp+1,dp+ln+1,a[i])-dp;
            dp[idx]=a[i];
        }
    }
    return ln;
}

int bin(int l,int r,int ks){
    while(l<r){
        int mid=l+r>>1;
        if(dp[mid]>=ks){
            l=mid+1;
        }else r=mid;
    }
    return l;
}

int LDS(){
    int ln=0;dp[ln]=inf;
    for(int i=1;i<=n;i++){
        if(dp[ln]>=a[i]){	// 可以更新 
            dp[++ln]=a[i];
        }else{
            int idx=bin(1,ln,a[i]);
                // dp[idx]<=a[i] 且 idx 最大 ,每一个结尾的数越大越好 
            dp[idx]=a[i];
        }
    }
    return ln;
}

int main(){
//	freopen("Luogu1020.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    int ans1=LDS();
    printf("%d\n",ans1);

    return 0;
}
