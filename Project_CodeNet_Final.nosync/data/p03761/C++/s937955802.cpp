#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(26,51);
    for(int ix=0;ix<n;ix++){
        string s; cin >> s;
        vector<int> tmp(26,0);
        for(int ix2=0;ix2<s.size();ix2++){
            tmp.at(s.at(ix2)-'a')++;
        }
        for(int ix2=0;ix2<26;ix2++) v.at(ix2) = min(tmp.at(ix2),v.at(ix2));
    }
    string ans = "";
    for(int ix=0;ix<26;ix++){
        //if(v.at(ix) == 0) break;
        for(int ix2 = 0;ix2 < v.at(ix); ix2++) ans += ('a'+ix);
    }
    cout << ans << endl;
}