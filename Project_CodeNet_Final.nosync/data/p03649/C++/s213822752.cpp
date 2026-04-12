#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    ll ans = 0;
    auto max_it = max_element(a.begin(), a.end());
    int max_index = distance(a.begin(), max_it);
    while (a[max_index] >= N) {
        ll cnt = a[max_index] / N;
        a[max_index] %= N;
        a[max_index] -= cnt;
        for (int i = 0; i < N; i++) a[i] += cnt;
        ans += cnt;
        max_it = max_element(a.begin(), a.end());
        max_index = distance(a.begin(), max_it);
    }
    cout << ans << endl;
    return 0;
}