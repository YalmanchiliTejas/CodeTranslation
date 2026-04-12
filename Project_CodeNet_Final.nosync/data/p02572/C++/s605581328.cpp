#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    long long int sum = 0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        sum = (sum+arr[i]);
    }

    long long int ans = 0;

    for(int i=0; i<n; i++) {
        ans = (ans+((arr[i]%MOD)*((sum-arr[i])%MOD))%MOD)%MOD;
        sum = sum-arr[i];
    }
    cout<<ans<<endl;

    return 0;
}