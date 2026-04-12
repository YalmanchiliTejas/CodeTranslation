#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int a[N];
int n;
string s;
void P() {
    for (int k = 0; k < n; ++k) {
        cout << (a[k] == 0 ? 'S' : 'W');
    }
    cout << endl;
}
bool check(int x, int y) {
    a[0] = x;
    a[1] = y;
    for (int i = 1; i < n - 1; ++i) {
        if ((a[i] == 1) ^ (s[i] == 'o')) {
            a[i + 1] = a[i - 1];
        } else {
            a[i + 1] = 1 - a[i - 1];
        }
    }
    if ((a[n - 1] == 1) ^ (s[n - 1] == 'o') ^ (a[n - 2] == a[0])) {
        return false;
    }
    if ((a[0] == 1) ^ (s[0] == 'o') ^ (a[n - 1] == a[1])) {
        return false;
    }
    return true;
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (check(i, j)) {
                P();
                exit(0);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
