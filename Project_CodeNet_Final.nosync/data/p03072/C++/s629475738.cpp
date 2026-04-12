#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; i++) cin >> as[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (as[j] > as[i]) ok = false;
        }
        if (ok) cnt++;
    }
    cout << cnt << endl;
}
