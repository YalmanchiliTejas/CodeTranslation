#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    int d[N];
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }
    int t = d[0];
    for (int i = 1; i < N; i++) {
        if (t - 10 < 0) {
            cout << "no\n";
            return 0;
        }
        t = max(d[i], t - 10);
    }
    t = d[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (t - 10 < 0) {
            cout << "no\n";
            return 0;
        }
        t = max(d[i], t - 10);
    }
    cout << "yes\n";
    return 0;
}
