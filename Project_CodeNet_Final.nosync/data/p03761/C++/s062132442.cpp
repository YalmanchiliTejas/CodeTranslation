#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back

void solve(){
    int n; cin >> n;
    map<char, int> mp;
    for(char c='a'; c<='z'; c++){
        mp[c] = 100;
    }
    
    REP(i, n){
        string s;
        cin >> s;
        map<char, int> mpp;
        for(char c='a'; c<='z'; c++){
            mpp[c] = 0;
        }
        REP(j, s.size()){
            mpp[s[j]] += 1;  
        }
        for(char c='a'; c<='z'; c++){
            mp[c] = min(mp[c], mpp[c]);
        }
    }
    string res = "";
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second != 100 && it->second != 0){
            REP(i, it->second){
                res += it->first;
            }
        }
    }
    cout << res << endl;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}