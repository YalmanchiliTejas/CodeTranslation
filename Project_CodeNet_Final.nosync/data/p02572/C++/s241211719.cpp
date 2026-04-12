#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

struct edge{
    int to,weight;
    edge(int to,int weight):to(to),weight(weight){}
};
using Graph = vector<vector<int>> ;
using GraphEdge = vector<vector<int>> ;

long long modinv(long long a, long long m=MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
    /*MODの割り算の際に
    a/＝b;
    を
    a *= modinv(b,MOD);
    とする。
        */
}
int main(){
    int N;cin >> N;
    const int MAXN = 200000;
    int A[MAXN];
    ll tmp[MAXN];
    rep(i,N)cin >> A[i];
    tmp[N-1] = 0;
    for(int i=N-2;i>=0;i--){
        ll tm = A[i+1] + tmp[i+1];
        tm %= MOD;
        tmp[i] = tm;
    }
    ll ans = 0;
    rep(i,N){
        ll tm = tmp[i]* A[i];
        tm %= MOD;
        ans += tm;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;

}