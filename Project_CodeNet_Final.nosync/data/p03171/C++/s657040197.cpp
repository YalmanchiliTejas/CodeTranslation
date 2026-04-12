#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = ~(1<<31);
#define fs first
#define sc second
#define pb push_back

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
    return (a % b + b) % b;
}

ll n;
vi A;
ll m[3020][3020];

ll dp(ll start, ll end) {
    if(start > end) {
        return 0;
    } else {
        if(m[start][end] != -1) return m[start][end];
        ll moves = start+(n-end-1);
        if(moves % 2 == 0) {
            return m[start][end] = max(dp(start+1,end)+A[start], dp(start,end-1)+A[end]);
        } else {
            return m[start][end] = min(dp(start+1,end)-A[start], dp(start,end-1)-A[end]);
        }
    }

}


int main() {
    cin.sync_with_stdio(false);
    memset(m,-1,sizeof(m));
    cin >> n;
    A = vi(n);
    rep(i,0,n) cin >> A[i];
    cout << dp(0,n-1) << endl;
    return 0;
}
