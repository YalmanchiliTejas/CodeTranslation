/**
 * @author torith
 * @date 2018-10-30
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int A[27];
    for (int i = 0; i < 27; ++i) {
        A[i] = 1e9;
    }

    for (int i = 0; i < N; ++i) {
        int B[27] = {};
        string s; cin >> s;
        for (int j = 0; j < s.length(); ++j) {
            B[s[j] - 'a'] += 1;
        }

        for (int j = 0; j < 27; ++j) {
            A[j] = min(A[j], B[j]);
        }
    }

    string ans = "";
    for (int i = 0; i < 27; ++i) {
        if(A[i] > 0) {
            for (int j = 0; j < A[i]; ++j) {
                ans += (char) ('a' + i);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

