#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;

void solve(){

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    ll sm = 0, pr = 0;

    for(int i = n-1; i >= 0; --i){
        pr += (ll)arr[i] * sm;
        sm += arr[i];
        pr %= mod;
        sm %= mod;

        //cout << pr << " " << sm << endl;
    }
    cout << pr;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //int test; cin >> test;
    //for(int t = 1; t <= test; ++t){
        solve();    
    //}

	return 0;
}

