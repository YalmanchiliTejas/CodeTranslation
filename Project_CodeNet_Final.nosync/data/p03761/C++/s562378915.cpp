#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ans(26,100);
    vector<int> now(26,0);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            now[s[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            ans[j] = min(ans[j],now[j]);
        }
        now.clear();
        now.resize(26);        
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<ans[i];j++){
            cout << char('a'+i);
        }
    }
    cout << endl;
}