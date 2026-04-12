#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for(int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
        if(x[i] > y[i]) swap(x[i], y[i]);
    }

    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int min_pos = 0, max_pos = 0;
    for(int i = 0; i < N; ++i) {
        if(x[i] < x[min_pos]) min_pos = i;
        if(y[i] > y[max_pos]) max_pos = i;
    }

    // min is in red, max is in blue
    const int r_min = x[min_pos];
    ll ans = 1LL * (*max_element(begin(x), end(x)) - r_min) * (y[max_pos] - *min_element(begin(y), end(y)));

    if(min_pos == max_pos) {
        cout << ans << endl;
        return 0;
    }

    // min ans max is in red
    const int r_max = y[max_pos];
    set<pii> blue;
    for(int i = 0; i < N; ++i) {
        if(i == min_pos)      blue.insert(make_pair(y[i], i));
        else if(i == max_pos) blue.insert(make_pair(x[i], i));
        else                  blue.insert(make_pair(min(x[i], y[i]), i));
    }
    for(int i = 0; i < N; ++i) {
        ans = min(ans, 1LL * (blue.rbegin()->first - blue.begin()->first) * (r_max - r_min));
        const auto p = *blue.begin();
        if(p.first >= y[p.second]) {
            break;
        }
        blue.erase(p);
        blue.insert(make_pair(y[p.second], p.second));
    }

    cout << ans << endl;
}