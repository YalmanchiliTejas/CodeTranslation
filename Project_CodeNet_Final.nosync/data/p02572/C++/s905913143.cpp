#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    int n;
    cin >> n;
    int arr[n];
    long long int sum =0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum+=arr[i]%mod;
        sum%=mod;
    }
    long long count=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        count+=arr[i];
        count %= mod;
        long long tsum = sum-count;
        if(tsum<0) tsum+=mod;
        ans += (long long)arr[i] * tsum;
        ans%=mod;
    }
    cout << ans;
    return 0;
}