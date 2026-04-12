#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using ull = unsigned long long;
using ll = long long;
using namespace std;

const ll M = 1000000007;

int main(void) {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= M;
    }

    vector<ll> b(n, 0);
    b[n-1] = a[n-1];


    for(int bi = 1; bi < n; ++bi) {
        b[(n-1)-bi] = (b[(n-1)-bi+1] + a[(n-1)-bi])%M;
    }
    // for(int bi = 0; bi < n; ++ bi){
    //     cout << b[bi] << " ";
    // }
    // cout << endl;

    ll ans = 0;
    for (int i = 0; i < n-1; ++i) {
        ans += (a[i]*b[i+1])%M;
        // cout << a[i] << "*" << b[i+1] << endl;
    }

    cout << ans%M << endl;
    return 0;
}