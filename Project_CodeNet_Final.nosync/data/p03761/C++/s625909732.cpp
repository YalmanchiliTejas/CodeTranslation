#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    map<char, int> m1;
    string s1;
    cin >> s1;
    for (int i = 0; i < s1.size(); ++i) {
        if(m1.count(s1[i])){
            m1[s1[i]]++;
        }else{
            m1[s1[i]] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        string s;
        cin >> s;
        map<char, int> m2;
        for (int i = 0; i < s.size(); ++i) {
            if(m2.count(s[i])){
                m2[s[i]]++;
            }else{
                m2[s[i]] = 1;
            }
        }
        for(auto x: m1){
            if(m2.count(x.first)){
                if(x.second > m2[x.first]){
                    m1[x.first]--;
                }
            }else{
                m1.erase(x.first);
            }
        }
    }

    string ans = "";
    for(auto x: m1){
        for (int i = 0; i < x.second; ++i) {
            ans.push_back(x.first);
        }
    }
    cout << ans << endl;
    return 0;
}