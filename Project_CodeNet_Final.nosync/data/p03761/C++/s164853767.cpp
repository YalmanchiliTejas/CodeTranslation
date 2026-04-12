#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ans(26, 50);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        vector<int> tmp(26, 0);
        for (int j = 0; j < s.size(); j++) tmp[s[j] - 'a']++;
        for (int j = 0; j < 26; j++) ans[j] = min(ans[j], tmp[j]);
    }
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < ans[i]; j++) cout << (char)(i + 'a');
    }
    cout << endl;
}