#include<cstdio>
#define ll long long
ll arr[55];
ll brr[55];
ll ans=0;
void fun(ll L,ll x)
{
    if(x==arr[L])
    {
        ans+=brr[L];
        return ;
    }
    else
    {
        if(x==1)
        {
            return ;
        }
        else if(x<arr[L-1]+2)
        {
            fun(L-1,x-1);
        }
        else if(x==arr[L]/2+1)
            ans+=brr[L]/2+1;
        else if(x>arr[L-1]+2)
        {
            x=x-arr[L-1]-2;
            ans+=brr[L-1]+1;
            fun(L-1,x);
        }

    }

}
int main()
{
    ll n,x;
    arr[0]=1;
    brr[0]=1;
    for(int i=1;i<=50;i++)
    {
        arr[i]=arr[i-1]*2+3;
        brr[i]=brr[i-1]*2+1;
    }
    ans=0;
    scanf("%lld%lld",&n,&x);
    fun(n,x);
    printf("%lld\n",ans);
    return 0;
}
