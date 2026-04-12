#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    deque<int> b;
    rep(i, n) {
        if (i % 2 == 0)
            b.push_back(a[i]);
        else
            b.push_front(a[i]);
    }
    if (n % 2 == 1) reverse(all(b));
    for (auto e : b) cout << e << " ";
    cout << endl;

    return 0;
}
