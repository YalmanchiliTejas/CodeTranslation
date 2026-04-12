#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int mod = 1000000007;
    ll sum = 0;
    for(int i = 0 ; i < n; i++){
        sum += arr[i];
        sum = sum%mod;
    }
    
    long ans = 0;
    for(int i = 0; i < n; i++){
        sum -= arr[i];
        if(sum < 0){
            sum += mod;
        }
        ans += arr[i]*sum;
        ans %= mod;
    }
    
    cout << ans << endl;
    
}
