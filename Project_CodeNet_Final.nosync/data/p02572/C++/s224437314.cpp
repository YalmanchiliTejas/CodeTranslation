#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

const ll m = 1000000007;
int main() {
    int n;
    ll s = 0, ans = 0;
    cin >> n;
    vector<ll>a(n);
    rep(i, n) {
        cin >> a[i];
        s += a[i];
    }
    //s = s % m;
    rep(i, n) {
        s = s - a[i];
        // s = s % m;
        ll tmp = s % m;
        ans += a[i] * tmp;
        ans = ans % m;
    }
    ans = ans % m;
    cout << ans << endl;
    
    return 0;
}