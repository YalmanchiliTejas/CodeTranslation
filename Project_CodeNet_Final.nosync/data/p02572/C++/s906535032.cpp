#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++) 
        cin >> a[i + 1];
    ll ans = 0;
    ll s[n + 1];
    ll mod = pow(10,9)+7;
    s[n] = a[n];
    for(int i = n - 1; i > 0; i--){
        s[i] = s[i + 1] + a[i];
        s[i] %= mod;
    }
    for(int i = 1; i < n; i++){
        ans += a[i] * s[i + 1];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}