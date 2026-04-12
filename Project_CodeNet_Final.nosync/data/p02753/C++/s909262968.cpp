#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    string s;
    cin >> s;
    set<char> st;
    st.insert(s[0]);
    st.insert(s[1]);
    st.insert(s[2]);
    if ((int)st.size() == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
