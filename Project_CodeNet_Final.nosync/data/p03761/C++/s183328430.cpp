#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main(void)
{
    ll n;
    cin >> n;
    vector<map<char,ll>> v(n);
    map<char,ll> mp;
    rep(i,n){
        string s;
        cin >> s;
        rep(j,s.size()) v[i][s[j]]++;
    }
    for(char c='a'; c<='z'; c++){
        ll mini = INF;
        rep(i,n) mini = min(mini, v[i][c]);
        mp[c] = mini;
    }
    string ans;
    for(auto c:mp){
        if(c.second > 0){
            rep(i,c.second) ans += c.first;
        }
    }
    cout << ans << endl;
    return 0;
}