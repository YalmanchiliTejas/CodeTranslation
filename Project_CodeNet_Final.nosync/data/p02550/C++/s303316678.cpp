#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 1e9 + 7;
const int cmod = 998244353;
const int N = 3e5 + 5;
const int inf = 1e18 + 2;


void solve(int Case) {
    int n , x , m ;
    cin >> n >> x >> m ;
    set<int> M ;
    M.insert(x) ;
    vector<int> v , s;
    v.push_back(x) ;
    int idx = 0;
    while(true) {
        int t = (x * x) % m ;
        if(M.find(t) != M.end()) {
            //cout << x << '\n';
            for(int i = 0 ; i < v.size() ; i ++) {
                if(v[i] == t) {
                    idx = i ;
                    break;
                }
            }
            for(int i = idx ; i < v.size() ;i ++) s.push_back(v[i]);
            break;
        }
        x = t ;
        v.push_back(t);
        M.insert(t) ;
    }
    int sz = 0 , ans = 0 ,sum = 0;
    for(int i = 0 ; i < v.size() ; i ++) {
        sz ++ ;
        sum += v[i] ;
        if(sz == n) {
            cout << sum << '\n';
            return;
        }
    }
    n -= sz ;
    ans += sum ;
    sz = 0;
    sum = 0;
    vector<int> p ;
    for(int i = 0 ; i < s.size() ; i ++) {
        sz ++ ;
        sum += s[i] ;
        if(sz == n) {
            cout << ans + sum << '\n';
            return ;
        }
        p.push_back(sum) ;
    }
    ans += (sum * (n / sz)) + ((n % sz) ? p[(n % sz) - 1] : 0) ;
    cout << ans << '\n';
}
/*
 */

int32_t main()
{
    fastio
    int testcase = 1;
    //cin >> testcase;
    int Case = 1;
    while(testcase --) {
        solve(Case);
    }
    return 0;
}
