#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> st;
    rep(i, s.size()) st.insert(s[i]);
    if (st.size() == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
}
