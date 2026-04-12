#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;

int MOD = 998244353;
// int MOD = 1000000007;

signed main(){

    ll n;
    cin >> n;
    vector<ll> s(n);
    rep(i,n)cin >> s[i];

    ll ans = 0;
    for(int c = 1;c < n;c++){
        ll res = 0;
        ll tmp = 0;
        if((n-1)%c == 0){
            for(int k = 0; k < n-1-k ;k += c){
                tmp += s[n-1-k] + s[k];
                res = max(res,tmp);
            }
        }else{
            for(int k = 0;k < n-1-c;k += c){
                tmp += s[n-1-k] + s[k];
                res = max(res,tmp);
            }
        }
        ans = max(ans,res);
    }
    cout << ans << endl;
     

    return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://abc127.contest.atcoder.jp/tasks/abc127_f
