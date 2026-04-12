#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll x;
ll a[51],p[51];
ll sum=0;

void dfs(int n,ll rest){
    //printf("%d %lld %lld\n",n,rest,sum);
    if(rest<=1)return;
    rest--;
    if(rest>=a[n-1]){
        sum+=p[n-1];
        rest-=a[n-1];
    }else{
        dfs(n-1,rest);
        rest=0;
    }
    if(rest<=0)return;
    rest--;
    sum++;
    if(rest>=a[n-1]){
        sum+=p[n-1];
        rest-=a[n-1];
    }else{
        dfs(n-1,rest);
    }
    if(rest<=1)return;
    rest--;
}

int main(void){
    scanf("%d%lld",&n,&x);
    a[0]=1;
    p[0]=1;
    for(int i=1;i<50;i++){
        a[i]=3LL+a[i-1]*2LL;
        p[i]=p[i-1]*2LL+1LL;
    }
    dfs(n,x);
    printf("%lld\n",sum);
    return 0;
}