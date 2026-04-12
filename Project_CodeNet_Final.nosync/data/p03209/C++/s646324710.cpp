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
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dfs(int N,ll X,vector<ll> a){
    if(N == 0) return 1;
    if(X == 1) return 0;
    if(X > 1 && X <= a[N]/2) return dfs(N-1,X-1,a);
    if(X == a[N]/2+1) return dfs(N-1,a[N-1],a)+1;
    if(X > a[N]/2+1 && X < a[N]) return dfs(N-1,a[N-1],a)+dfs(N-1,X-a[N]/2-1,a)+1;
    if(X == a[N]) return dfs(N-1,a[N],a)*2+1;
}

int main(){
    int N; cin >> N;
    ll X; cin >> X;
    vector<ll> a(N+1);
    a[0] = 1;
    rep(i,N){
        a[i+1] = a[i]*2+3;
    }
    ll ans = dfs(N,X,a);
    cout << ans << endl;
}

