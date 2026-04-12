#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(26, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            a.at((int)s[j]-97).at(i)++;
        }
    }
    
    for(int i = 0; i < 26; i++) {
        sort(a[i].begin(),a[i].end());
        for(int j = 0; j < a.at(i).at(0); j++) {
            cout << (char)(97+i);
        }
    }
    cout << endl;
    return 0;
}