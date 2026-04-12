#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl '\n'
using namespace std;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
typedef pair<ll, ll> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int h[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int cnt = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max <= h[i]) {
            cnt++;
            max = h[i];
        }
    }
    cout << cnt << endl;
    return 0;
}