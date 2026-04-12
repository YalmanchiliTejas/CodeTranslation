#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<ll> v(N + 10);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<ll> dp_fl(N + 10, 0);
    vector<ll> dp_ce(N + 10, 0);
    dp_fl[1] = 0;
    dp_ce[1] = v[1];
    dp_fl[2] = dp_ce[2] = max(v[1], v[2]);
    ll sum_of_odds = v[1];
    for (int i = 3; i <= N; i++) {
        if (i % 2 == 1) sum_of_odds += v[i];
        dp_fl[i] = max(dp_ce[i - 1], dp_fl[i - 2] + v[i]);
        dp_ce[i] = (i % 2 == 1) ? sum_of_odds : dp_fl[i];
    }
    cout << dp_fl[N] << endl;


    return 0;
}
