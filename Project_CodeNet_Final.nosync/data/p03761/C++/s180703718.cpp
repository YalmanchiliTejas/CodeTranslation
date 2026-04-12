#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    vector<vector<int>> word(n, vector<int>(26));
    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].length();j++){
            word[i][s[i][j] - 'a'] += 1;
        }
    }
    for(int j=0; j<26; j++){
        int count = 100;
        for(int i=0; i<n;i++) count = min(count, word[i][j]);
        for(int i=0; i<count;i++) cout << (char)('a' + j);
    }
    cout << endl;
    return 0;
}