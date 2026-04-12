#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const int max_n=2e5+10;
long long a[max_n];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        sum = sum % mod;
    }
    long long ans=0;
    for(int i=0;i<n;++i) {
        sum -= a[i];
        if(sum<0) sum+=mod;
        ans += a[i] * sum;
        ans = ans % mod;
    }
    cout<<ans<<endl;
    return 0;
}