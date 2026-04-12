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
int MOD = 1000000007;

signed main(){
    int h,w;
    cin >> h >> w;
    char a[110][110];
    rep(i,h) rep(j,w) cin >> a[i][j];
    int s[110] = {0};
    int t[110] = {0};
    rep(i,h){
        int c = 1;
        rep(j,w){
            if(a[i][j] == '#')c = 0;
        }
        if(c)s[i] = 1;
    }
    rep(j,w){
        int c = 1;
        rep(i,h){
            if(a[i][j] == '#')c = 0;
        }
        if(c)t[j] = 1;
    }
    rep(i,h){
        if(s[i] != 0)continue;
        rep(j,w){
            if(t[j] == 0) cout << a[i][j];
        }
        cout << endl;
    }
    
    
    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://agc030.contest.atcoder.jp/tasks/agc030_a
// rm -r -f test;oj dl http://abc107.contest.atcoder.jp/tasks/abc107_b