#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int n;
    cin >> n;
    vector<vector<int>> s_chars(n, vector<int>(26, 0));
    for ( int i = 0; i < n; i++ ) {
        string s;
        cin >> s;
        for ( auto itr : s )
            s_chars.at(i).at(itr - 'a')++;
    }

    /* 各文字を使える回数は s_chars の最小値分 */
    vector<int> ans(26, INT_MAX);
    for ( int alpha = 0; alpha < 26; alpha++ ) {
        for ( int i = 0; i < n; i++ )
            ans.at(alpha) = min(ans.at(alpha), s_chars.at(i).at(alpha));
    }

    for ( int alpha = 0; alpha < 26; alpha++ ) {
        for ( int i = 0; i < ans.at(alpha); i++ ) {
            cout << (char)('a' + alpha);
        }
    }
    cout << endl;

    return 0;
}
