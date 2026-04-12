#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    multiset<int> ms;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(-x);
        int tmp = x - 1;
        auto it = ms.find(-tmp);
        if (it != ms.end()) {
            ms.erase(it);
            continue;
        }
        it = ms.upper_bound(-tmp);
        if (it != ms.end()) ms.erase(it);
    }
    cout << ms.size();
    return 0;
}