#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main(){
    int n; cin >> n;
    vector<string> S(n);
    rep(i,n){
        string s; cin >> s;
        S[i] = s;
    }

    map<char,int> mp;
    for(char c = 'a';c<='z';c++){
        int mi=1010;
        rep(i,n){
            int cnt = 0;
            rep(j,S[i].size()){
                if(S[i][j]==c) cnt++;
            }
            mi = min(mi, cnt);
        }
        mp[c] = mi;
    }

    for(auto it : mp){
        rep(i,it.second) cout << it.first;
    }
    cout << endl;
}