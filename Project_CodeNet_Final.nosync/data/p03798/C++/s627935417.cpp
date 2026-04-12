#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n; string s; cin >> n >> s;
    // 先頭2種類を固定して矛盾が無いか試す
    for(ll i=0; i<4; i++){
        // 1文字余分に確保
        string tmp = "SS" + string(n-1, '-');
        if(i&(1LL<<0)) tmp[0] = 'W';
        if(i&(1LL<<1)) tmp[1] = 'W';
        for(ll i=1; i<n; i++){
            if(tmp[i] == 'S'){
                // 羊の場合
                if(s[i] == 'o'){
                    tmp[i+1] = tmp[i-1];
                }
                else{
                    tmp[i+1] = (tmp[i-1] == 'S' ? 'W' : 'S');
                }
            }
            else{
                // 狼の場合
                if(s[i] == 'o'){
                    tmp[i+1] = (tmp[i-1] == 'S' ? 'W' : 'S');
                }
                else{
                    tmp[i+1] = tmp[i-1];
                }
            }
        }
        if(tmp[0] == tmp[n]){
            if(tmp[0] == 'S'){
                if((s[0] == 'o' && tmp[1] != tmp[n-1]) || (s[0] == 'x' && tmp[1] == tmp[n-1])) continue; 
            }
            else{
                if((s[0] == 'o' && tmp[1] == tmp[n-1]) || (s[0] == 'x' && tmp[1] != tmp[n-1])) continue; 
            }
            cout << tmp.substr(0, n) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}