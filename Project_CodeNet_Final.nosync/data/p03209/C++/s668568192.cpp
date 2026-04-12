#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

ll solve(int n, ll x){
    if(n==0)return 1;
    ll len = (1LL<<(n+1))-3;
    ll bnum = (1LL<<n)-1;
    if(x==1)return 0;
    else if(x<=len+1)return solve(n-1, x-1);
    else if(x==len+2)return bnum+1;
    else if(x<=len*2+2)return bnum+1+solve(n-1, x-len-2);
    else return bnum*2+1;
}
int main(){
    int n;
    ll x;
    cin >> n >> x;
    cout << solve(n, x);
    return 0;
}