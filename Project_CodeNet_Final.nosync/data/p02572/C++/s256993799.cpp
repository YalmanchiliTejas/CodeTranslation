

#include<iostream>
#include<bits/stdc++.h>
#include<array>
using namespace std;
#define int long long
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define endl "\n"
#define with_tests int t; cin >> t; while(t--){ solve(); cout << endl; }
#define without_tests solve(); cout << endl;
#define CEIL(x, y) (ll)ceil((long double)(x)/(long double)(y))
#define epsilon 1e-9 
typedef long long ll;
const int mod = 1e9+7;
const int N = 1e5+1;

void solve(){
    
    
    int n;
    cin >> n;
    vector<int> a(n), pref(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    pref[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        pref[i] = (pref[i+1] + a[i])%mod;
    }
    int ans = 0;
    for(int i=0; i<n-1; i++){
        ans = (ans + (a[i]*pref[i+1])%mod)%mod;
    }
    cout << ans;

}

int32_t main(){

    fast_cin;
    // with_tests;
    without_tests;

    return 0;
}
