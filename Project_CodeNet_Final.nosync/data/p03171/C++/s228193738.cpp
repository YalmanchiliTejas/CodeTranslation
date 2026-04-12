#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define se second
#define fi first

typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e18;
const int mod = 1e9 + 7;

inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x;}
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x;}
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod;}
inline int power(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a) { return power(a, mod - 2);}

const int N = 3005;
int a[N],dp[N][N][2];

int f(int i,int j,int k){
    if(i>j) return 0;
    int &ret = dp[i][j][k];
    if(ret != -1) return ret;
    if(k==0){ // player 1 trying to maximize
        ret = max(a[i]+f(i+1,j,1-k),a[j]+f(i,j-1,1-k));
    } else { // player 2 trying to minimize
        ret = min(-a[i]+f(i+1,j,1-k),-a[j]+f(i,j-1,1-k));
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dp[i][j][0] = dp[i][j][1] = -1;
    cout << f(1,n,0) << endl;

    return 0;
}