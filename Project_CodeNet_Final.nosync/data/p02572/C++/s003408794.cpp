#include <bits/stdc++.h>
using namespace std;

long long int mod = 1000000007;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int prefixSum[n];
    int sum = arr[n-1];
    prefixSum[n-1]=sum;
    for(int i=n-2; i>=0; i--){
        sum = (sum%mod + arr[i]%mod)%mod;
        prefixSum[i]=sum;
    }

    long long int ans = 0;
    for(int i=0; i<n-1; i++){
        ans = (ans%mod + (arr[i]%mod*prefixSum[i+1]%mod)%mod)%mod;
    }

    cout<<ans<<'\n';

    return 0;
}
