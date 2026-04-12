#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[3030][3030];
int N;
vector<int> a;

ll solve(int l, int r){
    if(r-l == 1) return dp[l][r] = a[l];
    if(dp[l][r] != -1) return dp[l][r];

    ll res = max(a[l]-solve(l+1,r),a[r-1]-solve(l,r-1));
    return dp[l][r] = res;
}

int main(){
    cin >> N;
    a.resize(N);
    rep(i,N) cin >> a[i];
    rep(i,3030)rep(j,3030) dp[i][j] = -1;
    cout << solve(0,N) << endl;
    
}

