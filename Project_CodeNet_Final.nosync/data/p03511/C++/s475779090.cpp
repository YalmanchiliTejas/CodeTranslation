#include <bits/stdc++.h>
using namespace std;
using Int = long long;
string repeat(const string &s, int n) {
    string ans;
    for (int i = 0; i < n; i++) ans += s;
    return ans;
}
int main()
{
    int L; cin >> L;
    string S, T; cin >> S >> T;
    vector<int> dpS(L+1, -1e9), dpT(L+1, -1e9);
    dpS[0] = dpT[0] = 0;
    for (int i = 1; i < L+1; i++) {
        if (i - (int)S.size() >= 0) {
            dpS[i] = dpS[i - S.size()] + 1;
            dpT[i] = dpT[i - S.size()] + 0;
        }
        if (i - (int)T.size() >= 0) {
            dpS[i] = max(dpS[i], dpS[i - T.size()] + 0);
            dpT[i] = max(dpT[i], dpT[i - T.size()] + 1);
        }
    }
    string s = repeat(S, dpS[L]) + repeat(T, (L - S.size()*dpS[L]) / T.size());
    string t = repeat(T, dpT[L]) + repeat(S, (L - T.size()*dpT[L]) / S.size());
    cout << min(s, t) << endl;
    return 0;
}