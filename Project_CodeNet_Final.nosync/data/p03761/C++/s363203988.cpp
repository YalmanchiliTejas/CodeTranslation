#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<char, int> mp;
    for(char c='a';c<='z';++c)mp[c] = INT_MAX;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        map<char, int> m;
        for(auto c : s){
            m[c]++;
        }
        for(char c='a';c<='z';++c){
            mp[c] = min(mp[c], m[c]);
        }
    }

    string ans;
    for(char c='a';c<='z';++c){
        while(mp[c] > 0){
            ans.push_back(c);
            mp[c]--;
        }
    }

    cout << ans << endl;

    return 0;
}
