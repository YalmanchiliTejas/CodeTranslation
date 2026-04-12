#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int num_house = 0;
    for (int i = 0; i < n; ++i) {
        bool can_see = true;
        for (int j = 0; j < i; ++j)
            if (h[j] > h[i]) {
                can_see = false;
                break;
            }
        if (can_see) ++num_house;
    }

    cout << num_house << endl;

    return 0;
}
