#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define mod 1000000007
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;

    rep(i, 0, n) {
        if (s[i] != s[k - 1]) cout << '*';
        else cout << s[i];
    }
    cout << endl;
    return 0;
}
