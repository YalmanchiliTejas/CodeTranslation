#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string>S(n);
    for(int i = 0; i < n; i++) {
        cin >> S[i];
    }
    int ABC[26][50];
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 50; j++) {
            ABC[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < S[i].size(); j++) {
            ABC[(int)(S[i][j]-'a')][i]++;
        }
    }
    string ans = "";
    for(int i = 0; i < 26; i++) {
        int X = 2500;
        for(int j = 0; j < n; j++) {
            X = min(X,ABC[i][j]);
        }
        for(int j = 0; j < X; j++) {
            ans+=(char)(i+'a');
        }
    }
    cout << ans << endl;
}

