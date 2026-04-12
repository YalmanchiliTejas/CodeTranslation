#include<bits/stdc++.h>
using namespace std;

long long M = 1000000007;

long long mult(long long a, long long b) {
    return (a * b) % M;
}

int main() {
    int t = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<long long> arr(n), sum(n+1, 0);
        
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            sum[i+1] += arr[i] + sum[i];
            sum[i+1] %= M;
        }        
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            long long S = sum[n] - sum[i+1];
            if(S < 0) {
                S += M;
            }
            ans += mult(S, arr[i]);
            ans %= M;
        }
        cout<<ans<<endl;
    }
    return 0;
}