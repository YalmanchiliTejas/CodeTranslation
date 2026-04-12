#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pair<int, int>, int> ppi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef bitset<60> Bitset;
const ll INFL = 1LL << 60;
const int INF = 1000000005;
const int MAX = 300000;
const int MOD = 1000000007;
struct Graph{int to,coin; ll cost;};
struct Edge{int from,to,coin; ll cost;};
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b) { return (a * b) / GCD(a, b); }
//------------------------------------------------------------------------------------------------------------------------------
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
    int ans = INF;
    for(int i = 0; i <= 2*max(X,Y); i++) {
        int cnt = i/2;
        ans = min(ans,A*max(0,X-cnt)+B*max(0,Y-cnt)+C*i);
    }
    cout<<ans<<endl;
}
