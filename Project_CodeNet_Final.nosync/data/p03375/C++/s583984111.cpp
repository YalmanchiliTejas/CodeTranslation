//#pragma GCC optimize(3)

#include<bits/stdc++.h>
#define MST(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i = a ; i < b ; ++i)
#define per(i,a,b) for(int i = a ; i > b ; --i)
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using namespace std;

template<class T> void show(T *x,int len,int s = 0) {for(int i = s ; i < s+len-1 ; ++i) cerr << x[i] << ' ';cerr << x[s+len-1] << endl;}
void debug() {cerr << endl;}
template <typename T, typename... Args> void debug(T x,Args... args) {cerr << x << ' ';debug(args...);}
typedef long long LL;
typedef unsigned long long ULL;

typedef pair<LL,LL> pii;
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
typedef __gnu_pbds::priority_queue<pii,greater<pii>,pairing_heap_tag> heap;
typedef heap::point_iterator iter;
template<class T>
inline void cmin(T &A,const T &B) {A = (A<B?A:B);}
template<class T>
inline void cmax(T &A,const T &B) {A = (A>B?A:B);}

const int N = 3000+19;
int n,P;
int c[N][N],s[N][N];

int power(int a,int b,int p) {
    int ans = 1;
    for( ; b ; b >>= 1,a = 1ll*a*a%p)
        if(b&1) ans = 1ll*ans*a%p;
    return ans;
}

void solve() {
    cin >> n >> P;
    c[0][0] = 1;
    for(int i = 1 ; i < N ; ++i) {
        c[i][0] = c[i][i] = s[i][i] = 1;s[i][0] = 0;
        for(int j = 1 ; j < i ; ++j) {
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%P;
            s[i][j] = (s[i-1][j-1]+1ll*j*s[i-1][j]%P)%P;
        }
    }
    int ans = 0;
    for(int i = 0 ; i <= n ; ++i) {
        int res = 1ll*c[n][i]*power(2,power(2,n-i,P-1),P)%P*((i&1) ? P-1 : 1)%P,tmp = power(2,n-i,P);
        int tot = 0;
        for(int j = 0 ; j <= i ; ++j)
            tot = (tot+1ll*power(tmp,j,P)*s[i+1][j+1]%P)%P;
        ans = (ans+1ll*tot*res%P)%P;
    }
    cout << ans << endl;
}

signed main() {
    //srand((int)time(0));
    //ios::sync_with_stdio(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
}