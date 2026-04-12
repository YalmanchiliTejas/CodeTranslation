#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    long long int n;
    cin>>n;
    long long int a[n];
    long long int sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        if( i > 0) {
            sum += a[i]%MOD;
        }
    }
    sum = sum%MOD;
    long long int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            sum = (sum+MOD-a[i]%MOD)%MOD;
            ans += (a[i]%MOD * sum)%MOD;
        } else {
            ans += (a[i]%MOD * sum)%MOD;
        }
    }
    cout<<ans%MOD;
    return 0;
}