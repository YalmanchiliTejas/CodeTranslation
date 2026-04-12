#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int inf=1e9;
const int mod=998244353;
int x,m;
ll n;
int pre[maxn];
ll sum1[maxn];

int main(){
    scanf("%lld%d%d",&n,&x,&m);

    pre[x]=1;sum1[1]=x;

    int cnt=0,pos=inf;
    ll sum=0;
    for(int i=2;i<=n;i++){
        x=1ll*x*x%m;
     //   printf("x=%d\n",x);
        sum1[i]=sum1[i-1]+x;
        if(pre[x]){
            cnt=i-pre[x];
            pos=i;
            sum=sum1[i]-sum1[pre[x]];
            break;
        }
        pre[x]=i;
    }

    ll sumr=0;
    int cntr=0;
    for(int i=0;i<maxn;i++)
        if(pre[i]&&pre[i]+cnt<pos)cntr++,sumr+=i;

    if(!cnt){
        sum+=sumr;
        printf("%lld\n",sum);
        return 0;
    }

    sum*=(n-cntr)/cnt;
    sum+=sumr;

    int r=(n-cntr)%cnt;

    for(int i=1;i<=r;i++){
        sum+=x;
        x=1ll*x*x%m;
    }

    printf("%lld\n",sum);


    return 0;
}
