#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto v = vector<int>(26);
    for (char c : s)
        v[c - 'a']++;
    for (int i=0; i<n-1; i++) {
        cin >> s;
        auto w = vector<int>(26);
        for (char c : s)
            w[c - 'a']++;
        for (int i=0; i<26; i++) {
            if (w[i] == 0)
                v[i] = 0;
            else    
                v[i] = min(v[i], w[i]);
            //cout << i << " " << v[i] << endl;
        }
    }
    string ans = "";
    for (int i=0; i<26; i++) {
        for (int j=0; j<v[i]; j++) {
            ans += (char)(97 + i);
        }
    }
    cout << ans << endl;
}
