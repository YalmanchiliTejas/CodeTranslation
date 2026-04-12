#include<bits/stdc++.h>
#define ll long long
#define pi acos(-1.0)
#define sf(a)                scanf("%lld",&a)
#define sff(a,b)             scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define case(a,b)            printf("Case %lld: %lld\n",a,b)
#define pf(a)                printf("%lld\n",a)
#define pff(a,b)             printf("%lld %lld\n",a,b)
#define pb                   push_back
#define cln(x)               memset(x, 0, sizeof(x))
#define nl                   printf("\n");
const int N=123456;
ll arr[N], i, j;
using namespace std;
int main()
{
    ll a, b, c, x, y;
    while(sfff(a,b,c)==3)
    {
        sff(x,y);
        ll cost1, cost2, cost3;
        cost1=(x*a+y*b);
        ll mn=min(x,y);
        cost2=(mn*2*c);
        if(x>y)
        {
            cost2+=(a*(x-y));
        }
        else cost2+=(b*(y-x));
        ll mx=max(x,y);
        cost3=mx*c*2;
        //cout<<cost1<<" "<<cost2<<" "<<cost3<<endl;
        ll ans=min(cost1,min(cost2,cost3));
        pf(ans);
    }
    return 0;
}


/*
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
*/







