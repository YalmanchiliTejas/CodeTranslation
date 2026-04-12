#include<iostream>
#include<vector>
#include<map>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n";
#pragma GCC optimize "trapv"
using namespace std;
typedef long long int ll;
int mx =1e6+100;
int mod = 1e9+7;
long long moduloMultiplication(long long a,
                            long long b)
{
    long long res = 0;
  
    a %= mod;
  
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;

        a = (2 * a) % mod;
  
        b >>= 1;
    }
  
    return res;
}
  
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    ll tot=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        tot  = (tot%mod + a[i]%mod)%mod;
    }
    //
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        tot = (tot%mod-a[i]%mod+mod)%mod;
        ll val = moduloMultiplication(tot, a[i]);
         sum  = (sum%mod + val%mod)%mod;
    }
    cout<<sum<<endl;
    return 0;
}
