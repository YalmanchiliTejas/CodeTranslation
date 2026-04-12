#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl '\n'
using namespace std;
int dy[4] = {1,0,-1,0},dx[4] = {0,1,0,-1};
typedef pair<ll, ll> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> s >> k;
    char c = s[k - 1];
    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}