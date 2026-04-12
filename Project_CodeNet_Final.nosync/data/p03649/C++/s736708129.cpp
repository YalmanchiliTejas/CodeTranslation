#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N;
vector<ll> a;

void input(void){
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
}

bool _judge(ll k){
    vector<ll> a_copy = a;
    for (auto& ai : a_copy)
        ai += k - N + 1;
    ll tmp = 0;
    for (auto ai : a_copy)
        if (ai > 0)
            tmp += ai / (N + 1) + (ai % (N + 1) > 0 ? 1 : 0);
    return k >= tmp;
}

bool judge(ll k){
    for (ll i = k; i >= max(0LL, k - 100); --i)
        if (_judge(i)) return true;
    return false;
}

int main(void){
    input();
    ll ng = -1, ok = (ll)1e18;
    while (ok - ng > 1){
        ll mid = (ng + ok) / 2;
        if (judge(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}