using namespace std;
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define debug(x) cout << #x <<" = " << x << endl
#define MOD 1000000007
void solve()
{
ll n;
cin>>n;
ll arr[n];
ll sum=0;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
    sum+=arr[i];
    sum%=MOD;
}
ll ans=0;
for (int i = 0; i < n; i++)
{
    sum-=arr[i];
    sum=(sum+MOD)%MOD;
    ans=(ans+sum*arr[i])%MOD;
}
cout<<ans%MOD<<endl;
}
int main()
{
FASTIO
 long long int t;
 t=1;
 while(t--)
  solve();
  return 0;
}
