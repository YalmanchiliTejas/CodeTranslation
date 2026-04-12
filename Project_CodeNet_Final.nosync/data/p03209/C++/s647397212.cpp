#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, X;

ll layer_sum(ll n) {
    return (ll)pow(2, n) + (ll)pow(2, n) * 3 - 3;
}

ll patty_sum(ll n) {
    return (ll)pow(2, n+1) - 1;
}

ll patty_cnt(ll n, ll x) {
    if (n == 0) return 1; 
    else if (x == 1) return 0;
    else if (1 < x && x < layer_sum(n-1) + 2) {
        return patty_cnt(n-1, x-1);
    }
    else if (x == layer_sum(n-1) + 2) {
        return patty_sum(n-1) + 1;
    }
    else if (layer_sum(n-1) + 2 < x && x < layer_sum(n)) {
        return patty_sum(n-1) + 1 + patty_cnt(n-1, x-2-layer_sum(n-1));
    }
    else return patty_sum(n);
}

int main() {
    cin >> N >> X;

    cout << patty_cnt(N, X) << endl;    
    
    return 0;
}
