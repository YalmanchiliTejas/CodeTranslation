#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    string s;
    vector<int> alpha(26);
    for (int i = 0; i < 26; i++) {
        alpha[i] = 50;
    }

    for (int i = 0; i < n; i++) {
        vector<int> tmp(26);
        cin >> s;
        for (int j = 0; j < s.length(); j++){
            tmp[s[j] - 97] = tmp[s[j] - 97] + 1;
        }
        for (int j = 0; j < 26; j++){
            alpha[j] = min(alpha[j], tmp[j]);
        }
    }
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < alpha[i]; j++){
            printf("%c", 'a'+i);
        }
    }
    cout << endl;
}

