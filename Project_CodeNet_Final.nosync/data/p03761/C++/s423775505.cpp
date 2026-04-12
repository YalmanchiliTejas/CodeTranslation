#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> c(n, vector<int>(26));
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < s[i].size(); j++)
            c[i][s[i].at(j) - 'a']++;
    }
    vector<int> x(26);
    fill(x.begin(), x.end(), 51);
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < n; j++)
            x[i] = min(x[i], c[j][i]);
        for(int j = 0; j < x[i]; j++)
            cout << (char)(i + 'a');
    }
}