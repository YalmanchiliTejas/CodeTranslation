#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 0x3f3f3f3f
#define eps 1e-10
using namespace std;
string s;
map<pair<int,int>,bool>exist;
long long n,a[200005],sum[200005],ans,presum;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<n;i++){
        presum=sum[n]-sum[i];
        presum%=1000000007;
        ans+=a[i]*(presum);
        ans%=1000000007;
        
    }
    printf("%lld",ans);
}
