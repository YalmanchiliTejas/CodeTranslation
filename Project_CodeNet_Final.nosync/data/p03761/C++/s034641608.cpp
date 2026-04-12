#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<map<char, int>> mp(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto& c : s) mp[i][c]++;
    }
    
    map<char, int> cnt;
    for (char c = 'a'; c <= 'z'; c++) {
        int mn = INF;
        bool all = true;
        for (int i = 0; i < n; i++) {
            if (!mp[i].count(c)) all = false;
            mn = min(mn, mp[i][c]);
        }
        if (mn == INF || !all) continue;
        cnt[c] = mn;
    }
    
    for (auto& e : cnt) {
        for (int i = 0; i < e.second; i++) {
            cout << e.first;
        }
    }
    cout << endl;
    return 0;
}