#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100001
vector<ll> vec;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    ll ret = 0;
    if (n % 2 == 0) {
        for (int i = 0; i <= n / 2 - 2; i++) {
            ret -= vec[i] * 2;
        } 
        for (int i = n / 2 + 1; i <= n - 1; i++) {
            ret += vec[i] * 2;
        }
        ret = ret + vec[n / 2] - vec[n / 2 - 1]; 
    }
    else {
        ll ret1 = 0;
        ll ret2 = 0;
        // 足す方を増やす時
        for (int i = 0; i <= n / 2 - 2; i++) {
            ret1 -= vec[i] * 2;
        }
        for (int i = n / 2 + 1; i <= n - 1; i++) {
            ret1 += vec[i] * 2;
        }
        ret1 = ret1 - vec[n / 2] - vec[n / 2 - 1]; 
        //引く方を増やす時
        for (int i = 0; i <= n / 2 - 1; i++) {
            ret2 -= vec[i] * 2;
        }
        for (int i = n / 2 + 2; i <= n - 1; i++) {
            ret2 += vec[i] * 2;
        }
        ret2 = ret2 + vec[n / 2 + 1] + vec[n / 2]; 
        ret = max(ret1, ret2);
    }
    cout << ret << endl;
    return 0;
}