#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

#define ALL(a) (a).begin(),(a).end()
#define ZP(a, len) setfill('0') << setw(len) << right << a
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

signed main() {
    char c;
    cin >> c;
    string ans = "consonant";
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        ans = "vowel";
    }
    cout << ans << endl;
    return 0;
}