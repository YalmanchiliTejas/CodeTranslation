#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1000000;

int main() {
    ll N;
    ll ans = 0;
    cin >> N;
    vector<ll>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll i, j;
    ll right, left;
    left = A[0];
    right = A[N-1];
    ans += abs(right-left);
    i = 1;
    j = N-2;
    while (i <= j) {
        ll a, b, c, d;
        ll m;
        a = abs(left-A[i]);
        b = abs(left-A[j]);
        c = abs(right-A[i]);
        d = abs(right-A[j]);
        m = max({a, b, c, d}); 
        if (m == a) {
            ans += m;
            left = A[i];
            i++;
        } else if (m == b) {
            ans += m;
            left = A[j];
            j--;
        } else if (m == c) {
            ans += m;
            right = A[i];
            i++;
        } else {
            ans += m;
            right = A[j];
            j--;
        }
    }
    cout << ans << endl;
}
