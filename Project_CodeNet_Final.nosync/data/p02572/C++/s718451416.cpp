#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#define ll long long int
#define mod 1000000007

using namespace std;

int n;
ll a[200009],s[200009];

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> n;
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>> a[i];
        sum+=a[i];
    }

    for(int i=1;i<n;i++){
        sum -= a[i];
        s[i] = sum;
    }
    for(int i=1;i<n;i++){
        ans += ((s[i]%mod)*a[i])%mod;
    }
    cout<< ans%mod << endl;

    return 0;
}
