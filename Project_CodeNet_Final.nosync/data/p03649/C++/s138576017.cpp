/*
 * DATE : 2017-07-29
 * Algo :
*/
#include<bits/stdc++.h>
using namespace std;
/*------- Constants---- */

#define LL                      long long
#define Ulong                   unsigned long long
#define FOR(I,A,B)              for(long long i=0; i < n ; i++ )
#define REP(i,n)                for(long long i=0; i < n ; i++ )
#define mp                      make_pair
#define pb                      push_back
#define all(x)                  (x).begin(),(x).end()
#define PI                      acos(-1.0)
#define EPS                     1e-14
#define F                       first
#define S                       second
#define di(x)                   int x; input(x)
#define in(x)                   input(x)
#define in2(x,y)                in(x),in(y)
#define in3(x,y,z)              in(x),in2(y,z)
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl
#define nl                      cout<<endl
#define ms(ara_name,value)      memset(ara_name,value,sizeof(ara_name))
#define IO                      ios_base::sync_with_stdio(0);cin.tie(0)
#define READ                    freopen("in.txt","r",stdin)
#define WRITE                   freopen("out.txt","w",stdout)
template<class T> inline void input(T &x) {
    register char c = getchar();x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-'){neg = 1;c = getchar();}
    for(; c>47 && c<58 ; c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x = -x;
}
inline long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

/***************************** END OF TEMPLATE *******************************/

const int N = 1001;
int n;
LL a[N], sum = 0;
LL k;
vector<LL> coin[N];
unordered_map<LL,bool> dp[N];

bool Find(int idx, LL k)
{
    if(idx == n) return k == 0;
    if(dp[idx].count(k)) return dp[idx][k];
    if(coin[idx].size() == 0) return dp[idx][k] = 0;
    bool ret = 0;
    for(int i = 0; i < coin[idx].size() && ret == 0; i ++ ){
        ret |= Find(idx + 1, k - coin[idx][i]);
    }
    return dp[idx][k]= ret;
}
bool solve(LL k)
{
    for(int i = 0; i < n;i ++) dp[i].clear();
    for(int i = 0;i < n;i ++) coin[i].clear();
    for(int  i = 0; i < n; i ++ ) {
        for(int j = 0; j < n; j ++ ) {
            LL nk = a[i] + k - j;
            if(nk >= 0 && nk % (n+1) == 0) {
                coin[i].push_back(nk / (n+1));
            }
        }
        //db(coin[i].size());
        //cout << coin[i][0] << endl;
    }
    if(Find(0,k)) {
            cout << k << endl;
        return 1;
    }
    return 0;
}
int main()
{
    cin >> n;
    LL sum = 0;
    for(int i =0 ;  i < n ;i ++) cin >> a[i], sum += a[i];

    for(int i = n*(n-1); i>= (n-1) ; i --)  {
        k = sum - i;
        if(solve(k)) {
            return 0;
        }
    }

    return 0;
}
