#include <cstdio>
typedef long long ll;

int n;
ll a[55],s;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    while(true)
    {
        int Mp=0;
        ll Mv=0;
        for(int i=1;i<=n;++i)if(a[i]>Mv)Mv=a[Mp=i];
        if(Mv<n)break;
        ll Cnt=Mv/n;
        s+=Cnt;
        for(int i=1;i<=n;++i)
            if(i!=Mp)a[i]+=Cnt;
            else a[i]%=n;
    }
    printf("%lld\n",s);
    return 0;
}