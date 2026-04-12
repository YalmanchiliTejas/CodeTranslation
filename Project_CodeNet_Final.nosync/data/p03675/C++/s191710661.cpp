#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if ((i % 2) ^ (n % 2)) {
            q.push_front(a);
        } else {
            q.push_back(a);
        }
    }
    for (int i : q) {
        cout << i << ' ';
    }
    return 0;
}