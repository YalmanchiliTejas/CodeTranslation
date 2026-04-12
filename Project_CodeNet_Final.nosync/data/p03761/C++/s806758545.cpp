#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}


int main() {
    int n;cin >> n;
    vector<int> ans(26,0);
    string s1;cin >> s1;
    rep(i,s1.size())ans[s1[i]-'a']++;
    rep(i,n-1){
        vector<int> sans(26,0);
        string s;
        cin >> s;
        rep(k,s.size())sans[s[k]-'a']++;
        rep(i,26)ans[i]=min(ans[i],sans[i]);
    }
    string can;
    rep(i,26){
        rep(j,ans[i])can+='a'+i;
    }
    printf("%s\n",can.c_str());
}