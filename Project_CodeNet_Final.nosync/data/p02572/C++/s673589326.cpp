#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
    cin >> n;
    vector<long long int> arr(n, 0);
    vector<long long int> pre(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long int mod = 1000000007;
    pre[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        pre[i] = (pre[i+1] + arr[i+1])%mod;
    }
    long long int ans = 0;
    for( long long int i = 0; i < n-1; i++){
        ans = (ans + (arr[i]*pre[i])%mod)%mod;
    }
    cout << ans << endl;
}
