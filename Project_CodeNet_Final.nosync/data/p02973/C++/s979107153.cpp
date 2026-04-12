#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {
    ll N;
    cin >> N;

    ll A[N];
    for(ll i=0; i<N; i++) cin >> A[i];

    multiset<ll> S;
    S.insert(A[N-1]);
    ll cnt = 1;

    for(ll i=N-2; i>=0; i--) {
        auto it = S.upper_bound(A[i]);
        if(it == S.end()) {
            S.insert(A[i]);
            cnt++;
        } else {
            S.erase(it);
            S.insert(A[i]);
        }
    }

    cout << cnt << endl;

    return 0;
}