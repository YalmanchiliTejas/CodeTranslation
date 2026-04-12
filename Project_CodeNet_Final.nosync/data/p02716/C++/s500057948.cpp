#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=2e5+10;
int N;
int arr[MAXN];

typedef long long int ll;

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",arr+i);

    ll ans=0;

    if (N%2){
        ll sum=0;
        for(int i=1;i<=N-2;i+=2) sum+=arr[i];
        ans=sum;

        ll tailDiff=0,tailDiffMax=0;
        for(int i=N-2;i>=0;i-=2){
            sum-=arr[i];
            sum+=arr[i+1];
            tailDiff+=arr[i+2];
            tailDiff-=arr[i+1];
            tailDiffMax=max(tailDiffMax,tailDiff);
            ans=max(ans,sum+tailDiffMax);
        }

    }else{
        ll sum=0ll;
        for(int i=1;i<N;i+=2) sum+=arr[i];

        ans=sum;
        for(int i=N-1;i>=0;i-=2){
            sum+=arr[i+1];
            sum-=arr[i];
            ans=max(ans,sum);
        }
    }


    printf("%lld\n",ans);

    return 0;
}