#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    map<char, int> mp[n];
    string str;
    rep(i, n){
        cin >> str;
        rep(j, str.size()){
            mp[i][str[j]]++;
        }
    }
    for(auto ch : mp[0]){
        int mincnt = 51;
        rep(i, n){
            if(!mp[i].count(ch.first)){
                mincnt = 0;
                break;
            }
            mincnt = min(mincnt, mp[i][ch.first]);
        }
        rep(i, mincnt) cout << ch.first;
    }
    cout << endl;
    return 0;
}