#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int iinf = 1 << 28;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;

void work() {
    string s; cin>>s;
    if (s[0] != s[1] || s[1] != s[2]) {
        cout << "Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    work();
    return 0;
}
