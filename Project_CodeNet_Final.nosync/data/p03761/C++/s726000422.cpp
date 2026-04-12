#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        v.push_back(S);
    }

    int alphabet[n][26];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 26; j++) alphabet[i][j] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            alphabet[i][(int)v[i][j] - (int)'a']++;
        }
    }

    int mins[26];
    for(int i = 0; i < 26; i++) {
        int minimum = inf;
        for(int j = 0; j < n; j++) {
            minimum = min(minimum, alphabet[j][i]);
        }
        mins[i] = minimum;
    }
    string ans;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < mins[i]; j++) ans += (char)((int)'a' + i);
    }
    cout << ans;
    return 0;
}
