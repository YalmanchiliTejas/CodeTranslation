#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2000005;
const int mod = 1000000007;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    long long ans = 0 , sum  = 0 ;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ans = (ans+sum*a[i])%mod;
        sum = (sum+a[i])%mod;
    }
    cout << ans <<endl;
    return 0;
}
