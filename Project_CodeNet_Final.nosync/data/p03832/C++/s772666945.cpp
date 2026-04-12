#pragma gcc optimize("Ofast")

#include "bits/stdc++.h"
using namespace std;
typedef int64_t lld;
typedef pair<int,int> pii;
typedef pair<lld,lld> pll;
typedef pair<int,pll> pip;
typedef pair<pll,int> ppi;
typedef pair<lld,pll> plp;
typedef pair<pll,lld> ppl;
typedef pair<pll,pll> ppp;
template<typename T>
using maxHeap = priority_queue<T,vector<T>,less<T>>;
template<typename T>
using minHeap = priority_queue<T,vector<T>,greater<T>>;
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define jizz cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
inline void input(int &_x) {
    _x = 0;
    int _tmp = 1; char _tc = getchar();
    while((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
    if(_tc == '-') _tc = getchar(), _tmp = -1;
    while(_tc >= '0' && _tc <= '9') _x = _x*10+(_tc-48), _tc = getchar();
    _x *= _tmp;
}
inline void output(int _x) {
    char _buff[20]; int _f = 0;
    if(_x == 0)putchar('0');
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(_f-=1; _f >= 0; _f--)
        putchar(_buff[_f]);
    putchar('\n');
}
template<typename Iter>
ostream& _out(ostream &s, Iter b, Iter e) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}
template<class T1,class T2>
ostream& operator<<(ostream& out, pair<T1,T2> p) {
    return out << '(' << p.first << ", " << p.second << ')';
}
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) {
     return _out(s,c.begin(),c.end());
 }
#ifdef erd1
    #define pprint(x) cerr<<__PRETTY_FUNCTION__<<":"<<__LINE__<<" - "<<(#x)<<"="<<(x)<<endl
#else
    #define pprint(x)
#endif

const int mod = 1000000007;
// code starts here
int invmod(int a, int b = mod, int s0 = 1, int s1 = 0){
    return b? invmod(b, a%b, s1, (s0-(lld)(a/b)*s1%mod+mod)%mod) : s0;
}

int fpow(int a, int b){
    int ans = 1;
    do if(b&1) ans = (lld)ans * a %mod;
    while(a = (lld)a*a%mod, b>>=1);
    return ans;
}

vector<int> fact, ifact, dp;
inline void MOD(int& x){if(x > mod)x-=mod;}
signed main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    fact.resize(n+1); ifact.resize(n+1); fact[0] = ifact[0] = 1;
    for(int i = 1; i <= n; i++)ifact[i] = invmod(fact[i] = (lld)fact[i-1]*i%mod);
    dp.resize(n+1);
    dp[0] = 1;
    for(int j = a; j <= b; j++)
        for(int i = n; i >= 1; i--)
            for(int k = c; k <= d && j*k <= i; k++)
                MOD(dp[i] += (lld)dp[i-j*k]*fact[i]%mod*ifact[i-j*k]%mod*invmod(fpow(fact[j], k))%mod*ifact[k]%mod);
    cout << dp[n] <<endl;
}
