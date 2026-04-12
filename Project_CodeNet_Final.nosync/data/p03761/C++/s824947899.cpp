#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n; cin >> n;
    vector<vector<ll>> r(n, vector<ll>(26,0));
    rep(i, 0, n){
        string s;
        cin >> s;
        for(auto c : s){
            r[i][c-'a']++;
        }
    }
    vector<ll> mns(26, 1e9);
    rep(i, 0, 26){
        rep(j, 0, n){
            mns[i] = min(mns[i], r[j][i]);
        }
    }

    rep(i, 0, 26){
        rep(j, 0, mns[i]){
            cout << (char)(i+'a');
        }
    }
    cout << endl;
    return 0;
}