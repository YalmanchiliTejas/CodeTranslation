#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5;
int n,m,a[N+5];
int main()
{
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll ans1=0;
    int minus2=(n-1)/2;
    int plus2=(n-2)/2;
    int plus1=n%2 ? 2 : 1;
    int minus1=2-plus1;
    for (int i=0;i<n;i++)
    {
        if (minus2)
        {
            minus2--;
            ans1-=2*a[i];
        }
        else if (minus1)
        {
            minus1--;
            ans1-=a[i];
        }
        else if (plus1)
        {
            plus1--;
            ans1+=a[i];
        }
        else ans1+=2*a[i];
    }
    ll ans2=0;
    minus2=(n-2)/2;
    plus2=(n-1)/2;
    plus1=n%2 ? 0 : 1;
    minus1=2-plus1;
    for (int i=0;i<n;i++)
    {
        if (minus2)
        {
            minus2--;
            ans2-=2*a[i];
        }
        else if (minus1)
        {
            minus1--;
            ans2-=a[i];
        }
        else if (plus1)
        {
            plus1--;
            ans2+=a[i];
        }
        else ans2+=2*a[i];
    }
    cout<<max(ans1,ans2);
    return 0;
}