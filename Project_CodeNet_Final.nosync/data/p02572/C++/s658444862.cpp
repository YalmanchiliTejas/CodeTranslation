#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
long long int s[200005];
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        s[i+1]=(s[i]+a[i])%mod;
    }
    long long int ans=0;
    long long int tmp;
    for(int i=0;i<n-1;i++){
        tmp = (a[i]*(s[n]-s[i+1]+mod))%mod;
        ans += tmp%mod;
        ans %= mod;
    }
    cout << ans;
}