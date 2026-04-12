#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
    ll n;
    cin >> n;

    string s[n];
    rep(i, n){
        cin >> s[i];
    }

    sort(s[0].begin(), s[0].end());
    map<char, ll> st;
    map<char, ll> st_new;

    rep(i, s[0].size()){
        st[s[0][i]]++;
        st_new[s[0][i]]++;
    }

    for(pair<char, ll> str: st){
        for(int i = 1; i < n; i++){
            ll count = 0;
            rep(j, s[i].size()){
                if(str.first == s[i][j]) count++;
            }
            str.second = min(str.second, count);
            st_new[str.first] = str.second;
        }
    }

    for(pair<char, ll> str: st_new){
        rep(i, str.second){
            cout << str.first;
        }
    }
    cout << endl;
}
