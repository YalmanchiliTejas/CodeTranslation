#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
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
/*----------------------------------------------------------------*/

// int MOD = 998244353;
int MOD = 1000000007;


/*----------------------------------------------------------------*/
signed main(){

    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    x *= 2;
    y *= 2;
    
    int ans = 0;
    while(x > 0 && y > 0){
        ans += min(a+b,2*c);
        x -= 2;
        y -= 2;
    }
    while(x > 0){
        ans += min(a,2*c);
        x -= 2;
    }
    while(y > 0){
        ans += min(b,2*c);
        y -= 2;
    }
    cout << ans << endl;

    


	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=c++14 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c
// rm -r -f test;oj dl https://pakencamp-2019-day3.contest.atcoder.jp/tasks/pakencamp_2019_day3_c
// rm -r -f test;oj dl https://abc095.contest.atcoder.jp/tasks/arc096_a