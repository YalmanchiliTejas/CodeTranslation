#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';

ll gcd(ll a,ll b) {
    while(1) {
        if(a < b) swap(a, b);
        if(!b) break;
        a %= b;
    }
    return a;
}
int main() {
    ll n;
    cin>>n;
    vector<string>s(n);
    rep(i,n)cin>>s[i];
    rep(i,26) {
        int m = 100;
        rep(j, n)m = min(m, (int) count(begin(s[j]), end(s[j]),(char)i+97));
        rep(j, m) cout <<(char)(i+97);
    }
    cout << endl;
}

