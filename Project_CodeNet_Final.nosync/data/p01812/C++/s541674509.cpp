#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define int ll
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<vi> vvi;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

signed main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vi d(m);
    rep(i,m) cin >> d[i], d[i]--;
    vi rev(n,-1);
    rep(i,m)rev[d[i]] = i;
    vvi v(n,vi(k));
    rep(i,n)rep(j,k)cin >> v[i][j], v[i][j]--;
    vi dp(1<<m,(ll)INF*INF);
    dp[(1<<m)-1] = 0;
    queue<int> q;
    q.push((1<<m)-1);
    while(q.size()){
        int bit = q.front();
        q.pop();
        if(bit == 0)continue;
        rep(i,k){
            int nbit = 0;
            rep(j,m)if(bit&(1<<j)){
                int nr = v[d[j]][i];
                rep(x,m)if(d[x] == nr) nbit |= (1<<x);
            }
            if(dp[nbit] > dp[bit]+1){
                q.push(nbit);
                dp[nbit] = dp[bit]+1;
            }
        }
    }
    cout << dp[0] << endl;
}

