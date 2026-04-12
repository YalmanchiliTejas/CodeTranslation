#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...) (void)0
#endif
#define MP make_pair
#define PB push_back
#define LL long long
#define pii pair<int,int>

#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
//const int inf = 0x7fffffff; //beware overflow
//const LL INF = 0x7fffffffffffffff; //beware overflow
#define mem(x, y) memset(x, (y), sizeof(x) );
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
     return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
    s << "[ ";
    for (auto it : c) s << it << " ";
    s << "]";
    return s;
}
template<typename T>
ostream& operator << (ostream &o, const set<T> &st) {
    o << "{";
    for (auto it=st.begin(); it!=st.end(); it++) o << (it==st.begin() ? "" : ", ") << *it;
    return o << "}";
}
template<typename T1, typename T2>
ostream& operator << (ostream &o, const map<T1, T2> &mp) {
    o << "{";
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        o << (it==mp.begin()?"":", ") << it->fi << ":" << it->se;
    }
    o << "}";
    return o;
}
inline LL getint(){
   LL _x=0,_tmp=1; char _tc=getchar();
   while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
   if( _tc == '-' ) _tc=getchar() , _tmp = -1;
   while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
   return _x*_tmp;
}
#define maxn
constexpr int mod = 1e9+7;
int fac_inv[1005], fac[1005];
void add(int &l, int r) {
    l = (LL)(l+r)%mod;
}
void mul(int &l, int r) {
    l = (l*1LL*r)%mod;
}
int mypow(int a, int b) {
    int ret=1;
    int base=a;
    while(b) {
        if(b&1) mul(ret, base);
        b >>= 1;
        mul(base, base);
    }
    return ret;
}
int C(int n, int k) {
    if( k > n ) return 0;
    return fac[n]*1LL*fac_inv[k]%mod*fac_inv[n-k]%mod;
}
int f(int n, int k, int i) {
    if( n < k*i ) return 0;

    int ret = C(n, n-k*i);
    for(int ii=k*i;ii;ii-=i) mul(ret, C(ii,i));
    mul(ret, fac_inv[k]);
    return ret;
}
int dp[1005][1005];
int main() {
    fac[0] = 1;
    for(int i=1;i<=1000;i++) fac[i] = fac[i-1]*1LL*i%mod;
    fac_inv[1000] = mypow(fac[1000], mod-2);
    for(int i=999; i >=0 ;i--) fac_inv[i] = fac_inv[i+1]*1LL*(i+1)%mod;
    for(int i=1;i<=1000;i++) assert( fac_inv[i]*1LL*fac[i]%mod == 1);


    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for(int i=a; i<=b; i++) {

       if( i==a ) {
           dp[i][0] = 1;
            for(int k=c; k<=d && k*i <= n;k++) {
                dp[i][k*i] = f(n, k, i);
            }
            continue;
        }

        for(int j=0; j<=n;j ++) {
            if( !j ) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j]=dp[i-1][j];
            for(int k=c; k <= d && j  >= k*i ; k++)
                add(dp[i][j], (dp[i-1][j-k*i])*1LL*f(n-j+k*i, k, i)%mod );
        }
    }
    cout << dp[b][n] << endl;
}

