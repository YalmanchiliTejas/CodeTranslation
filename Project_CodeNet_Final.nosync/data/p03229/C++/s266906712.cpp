#include <bits/stdc++.h>
using namespace std;



// last submission

typedef long long  int ll;
#define s(n) scanf("%lld",&n)
#define s2(n,m) scanf("%lld%lld",&n,&m)
ll n,a[100005];
bool cm(ll x,ll y)
{
    return x>=y;
}
ll mx()
{

    ll sum = 0;
    ll lv,rv;
    lv = rv = a[0];
    ll i =1,j=n-1;
    ll on,tw,tr,fr,mxx;
    while(i<=j)
    {
        on = abs(lv-a[i]);
        tw  = abs(lv-a[j]);
        tr = abs(rv-a[i]);
        fr = abs(rv-a[j]);

        mxx = max(on,max(tw,max(tr,fr)));

       // cout<<lv<<" "<<rv<<" "<<i<<" "<<j<<" "<<mx<<endl;

        if(mxx==on)
            lv = a[i++];

        else if(mxx==tw) lv = a[j--];
        else if(mxx==tr) rv=a[i++];
        else
            rv = a[j--];
        sum+=mxx;

    }
    return sum;
}

int main()
{

    s(n);
    for(ll i=0; i<n; i++) s(a[i]);
    sort(a,a+n);
    ll ans = mx();


    printf("%lld\n",ans);





}
