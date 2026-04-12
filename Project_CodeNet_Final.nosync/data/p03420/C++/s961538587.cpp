#include<bits/stdc++.h>
#define maxn 203040

using namespace std;
typedef long long ll;
ll n,m,r,d,ans;

int main()
{
    scanf("%d%d",&n,&m);
    if (m==0){cout << n*n << endl;return 0;}n++;
    for (int i=m+1;i<n;i++)
    {
        r=n/i; ans+=r*(i-m);
        d=n%i; ans+=max(0ll,d-m);
    }
    cout << ans << endl;
}
