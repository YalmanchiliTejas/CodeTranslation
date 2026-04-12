#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1095
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    ll n, i, j;
    ll sum, mod=1000000007, tmp1, str, tmp2;
    scanf("%lld", &n);
    ll arr1[n], arr2[n];
    for (i=0; i<n; i++) scanf("%lld", &arr1[i]);
    for (i=0; i<n; i++) arr2[i]=arr1[i];
    for (i=1; i<n; i++) arr1[i]+=arr1[i-1];
    sum=0;
    str=arr1[n-1];
    for (i=0; i<n; i++) {
        tmp1=arr1[i];
        tmp2=str-tmp1;

        tmp1=arr2[i];
        tmp2=((tmp2%mod)*(tmp1%mod))%mod;
        sum=((sum%mod)+(tmp2%mod))%mod;
    }
    printf("%lld\n", sum);
    return 0;
}
