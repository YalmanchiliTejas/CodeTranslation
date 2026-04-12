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
    int n,m;
    cin >> n >> m;
    int ans = 0;
    int r[10][10] = {0};
    rep(i,m){
        int a,b;
        cin >> a >> b;
        r[a-1][b-1] = 1;
        r[b-1][a-1] = 1;
    }
    vector<int> s(n);
    rep(i,n)s[i] = i;
    do {
        int c = 1;
        //debug_vec(s);
        rep(i,n-1){
            if(r[s[i]][s[i+1]] == 0)c = 0;
        }
        if(c == 1)ans++;
    } while (next_permutation(s.begin()+1,s.end()));
    cout << ans << endl;


    

    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://abc054.contest.atcoder.jp/tasks/abc054_c
// rm -r -f test;oj dl http://yahoo-procon2017-qual.contest.atcoder.jp/tasks/yahoo_procon2017_qual_c