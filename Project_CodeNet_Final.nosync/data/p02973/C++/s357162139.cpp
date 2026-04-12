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
    int n;
    cin >> n;
    int a[100010];
    rep(i,n)cin >> a[i];
    multiset<int> c;
    int maxi = 0;
    int mini = 0;
    int s = 0;
    rep(i,n){
        if(c.size() == 0){
            c.insert(a[i]);
            maxi = a[i];
            mini = a[i];
        }else{
            auto itr = c.lower_bound(a[i]);
            if(itr == c.begin())c.insert(a[i]);
            else{
                itr--;
                c.erase(itr);
                c.insert(a[i]);
            }
        }
    }
    cout << c.size() << endl;

    return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://abc134.contest.atcoder.jp/tasks/abc134_b