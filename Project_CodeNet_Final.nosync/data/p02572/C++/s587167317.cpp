/**
 *    author:  RM07
 *    created: August 29, 2020 5:42 PM
 *    motto: Knowledge is Power, Strive for Excellence
**/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
signed main(){
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int *suffix = new int[n+1];
    suffix[n] = arr[n];
    for(int i = n - 1; i >=1; i--) {
        suffix[i] = (suffix[i+1] % mod) + (arr[i] % mod);
        suffix[i] = suffix[i] % mod;
    }
    int ans = 0;
    for(int i = 1; i <= n -1; i++) {
        ans += ((arr[i] % mod) * (suffix[i+1] % mod)) % mod;
    }
    cout << ans % mod << endl;
}