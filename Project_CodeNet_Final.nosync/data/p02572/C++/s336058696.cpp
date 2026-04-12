#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;

int main(){
    int n ;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n ;i++) cin >> a.at(i);
    int x = 0;
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        ans = (ans + (long long)a.at(i) * x) % mod;
        x = (x + a.at(i)) % mod;
    }
    cout << ans << endl;
    return 0;
}