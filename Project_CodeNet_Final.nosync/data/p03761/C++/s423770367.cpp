#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const long long INF = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
#define int long long
signed main(void){
    int n; cin>>n;
    vector <int> data(26, INF); 
    rep(i, n){
        string s; cin>>s;
        vector <int> tmp(26); 
        rep(j, s.size()) tmp[s[j] - 'a']++;
        rep(j, 26)  chmin(data[j], tmp[j]);
    }
    rep(i, 26){
        while(data[i]){
            cout<<char('a' + i);
            data[i]--;
        }
    }
}
