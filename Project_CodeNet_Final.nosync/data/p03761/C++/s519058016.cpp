#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    int n; cin>>n;
    vector<string> a(n);
    vector<map<char,int>> mp(n);
    rep(i,0,n) cin>>a[i];

    rep(i,0,n){
        rep(j,0,a[i].size()){
            mp[i][a[i][j]]++;
        }
    }
    
    string ans="";
    rep(i,0,26){
        int mini=INF;
        rep(j,0,n){
            mini=min(mini,mp[j][(char)(i+'a')]);
        }
        // debug(mini);
        rep(k,0,mini){
            ans.push_back((char)(i+'a'));
        }
    }
    cout<<ans<<endl;
    
}