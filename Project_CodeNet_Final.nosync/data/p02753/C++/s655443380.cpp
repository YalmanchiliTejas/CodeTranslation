#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') a++;
        if (s[i] == 'B') b++;
    }
    if (a == 3 or b == 3) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}

