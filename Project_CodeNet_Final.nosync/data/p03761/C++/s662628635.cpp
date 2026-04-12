#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    rep(j,s.size()){
        mp[s[j]]++;
    }
    rep(i,n-1){
        cin >> s;
        map<char, int> cnt;
        rep(j,s.size()){
            cnt[s[j]]++;
        }
        for(auto p : mp){
            if(cnt[p.first] < p.second){
                mp[p.first] = cnt[p.first];
            }
        }
    }
    string ans = "";
    for(auto p : mp){
        rep(j,p.second) ans += p.first;
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}