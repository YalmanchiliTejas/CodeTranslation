#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<lli>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


ll total[51];
ll paty[51];

ll rec(ll x, ll level){ 
    if(x==1){
        if(level == 0) return 1;
        else return 0;
    }
    if(1 < x && x <= total[level]/2) return rec(x-1, level-1);
    if(x == total[level]/2+1) return paty[level-1]+1;
    if(total[level]/2+1 < x && x <= total[level]-1) return paty[level-1] + 1 + rec(x - (total[level]/2+1), level-1);
    return paty[level];
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, x;
    cin >> n >> x;

    total[0] = 1;
    paty[0] = 1;
    rep(i, n){
        total[i+1] = 2*total[i] + 3;
        paty[i+1] = 2*paty[i] + 1;
    }

    cout << rec(x, n) << endl;

    return 0;
}