#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
typedef vector<int> vi;

int main() {
    int n,i;
    cin >> n;
    long long mod = 1000000007;
    vi a(n);
    long long sum =0,ans =0;
    f(i,0,n)
    {
        cin >> a[i];
        sum += a[i];
    }
    i=0;
    int j=0;
    f(i,0,n-1)
    {
        sum = (sum -a[i]);
        ans += ((sum%mod)*(a[i]%mod))%mod;
        ans %= mod;
    }
    cout << ans << endl;

   return 0;
}
