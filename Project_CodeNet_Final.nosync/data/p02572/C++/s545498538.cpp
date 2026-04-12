#define Oo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
typedef long long ll;
ll n;
ll a[200005];
ll t[200005];
ll mod=1000000007;
int main()
{
      Oo
      cin>>n;
      for (int i=1; i<=n; i++)cin>>a[i];
      for (int i=n; i>=1; i--)
      {
            if(i==n)t[i]=a[i];
            else
            {
                  t[i]=t[i+1]+a[i];
            }
            t[i]%=mod;
      }
      ll ans=0;
      for (int i=1; i<=n; i++)
      {
            ans+=(a[i]*t[i+1]%mod);
            ans%=mod;
      }
      cout << ans << endl;
	return 0;
}
