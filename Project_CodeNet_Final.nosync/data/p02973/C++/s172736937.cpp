#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    int N;
    cin >> N;

    int ans = 1;
    V<int> maxPerColor;
    int A;
    cin >> A;
    maxPerColor.push_back(A);
    for (int i = 1; i < N; i++) {
        int A;
        cin >> A;
        auto itr = lower_bound(maxPerColor.begin(), maxPerColor.end(), A);
        int idx = distance(maxPerColor.begin(), itr) - 1;
        if (idx == -1) {
            ans++;
            maxPerColor.insert(maxPerColor.begin(), A);
        } else {
            maxPerColor[idx] = A;
        }
    }
    cout << ans << endl;

    return 0;
}