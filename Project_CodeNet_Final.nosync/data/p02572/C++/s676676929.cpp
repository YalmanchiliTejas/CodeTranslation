#include "bits/stdc++.h"
#define ll long long int
#define ld long double
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pii;

int main() {
    fastIO;
    int n;
    cin >> n;

    int arr[n];
    ll pref[n];

    for (int i = 0; i < n; i++) {
//        arr[i] = 1e9;
        cin >> arr[i];
    }

    pref[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        pref[i] = pref[i + 1] + arr[i + 1];
    }

    // pref[i] = prefix sum from i + 1 to the end

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ((ll) arr[i]) * (pref[i] %= MOD);
        sum %= MOD;
    }

    cout << sum;

}
