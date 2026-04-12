#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll a[200000+5], s[200000+5];
ll const c=1e9+7;
int main()
{
    ll n, l, i, k, j, m ;
    cin >> n ;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        s[i]=a[i];
        s[i]=(s[i]+s[i-1])%c;
    }
    m=0;
    for(i=2; i<=n; i++)
    {
        k=(a[i]*s[i-1])%c;
        m+=k;
        m%=c;
    }
    cout << m ;
    return 0;
}