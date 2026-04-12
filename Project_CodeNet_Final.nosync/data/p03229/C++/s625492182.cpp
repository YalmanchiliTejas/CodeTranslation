#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
long long a[100010],b[100010];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    b[(n-1)/2]=a[0];
    int l,r,ll,rr;
    l=r=(n-1)/2;
    ll=1;rr=n-1;
    int cnt=0;
    while(ll<=rr)
    {
        if(cnt%4==0)
            b[++r]=a[rr--];
        else if(cnt%4==1)
            b[--l]=a[rr--];
        else if(cnt%4==2)
            b[++r]=a[ll++];
        else b[--l]=a[ll++];
        cnt++;
    }
    long long ans1=0;
    for(int i=0;i<n-1;i++)
        ans1+=abs(b[i+1]-b[i]);
    b[(n-1)/2]=a[n-1];
    l=r=(n-1)/2;
    ll=0;rr=n-2;
    cnt=0;
    while(ll<=rr)
    {
        if(cnt%4==0)
            b[++r]=a[ll++];
        else if(cnt%4==1)
            b[--l]=a[ll++];
        else if(cnt%4==2)
            b[++r]=a[rr--];
        else b[--l]=a[rr--];
        cnt++;
    }
    long long ans2=0;
    for(int i=0;i<n-1;i++)
        ans2+=abs(b[i+1]-b[i]);
    printf("%lld\n",max(ans1,ans2));
    return 0;
}
