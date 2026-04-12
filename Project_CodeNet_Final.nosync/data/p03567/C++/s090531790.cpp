#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>
#define all(A) A.begin(), A.end()

int main() {
    string s; cin >> s;

    bool ans = false;
    rep(i,s.size()-1){
        if(s[i] == 'A' && s[i+1] == 'C'){
            ans = true;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}