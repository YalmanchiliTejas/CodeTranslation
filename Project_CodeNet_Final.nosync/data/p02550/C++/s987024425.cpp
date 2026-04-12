#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,N,j) for(int i = (N-1);i >= (j);i--)
#define _rec(i,N,j) for(int i = (N);i >=(j);i--)
#define ALL(x) x.begin(),x.end()
#define MEM(a,n) memset(a,n,sizeof(a))
#define fst first
#define scd second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int get_int(){int x;scanf("%d",&x);return x;}
LL get_ll(){LL x;scanf("%lld",&x);return x;}
double get_db(){double x;scanf("%lf",&x);return x;}

template<typename T> int chmin(T &a,T b){if(a > b){a = b;return 1;}else return 0;}
template<typename T> int chmax(T &a,T b){if(a < b){a = b;return 1;}else return 0;}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {_for(i,0,v.size()) os << v[i] << " ";return os;}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){for(auto a:v) os << a <<" ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){os << v.fst <<" "<<v.scd << " ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const map<T1,T2>& v){for(auto a:v) cout << a << endl;return os;}

static const int dx[8] = { -1,  0, 1, 0,  1, -1,  1, -1};
static const int dy[8] = {0,  1, 0,  -1,  1, -1, -1,  1};
const double pi  = acos(-1.0);
const double eps = 1e-8;
const LL  INF  = 0x3f3f3f3f3f3f3f3f;
const int inf  = 0x3f3f3f3f;

const int maxn = 1e5 + 5;

LL sum[maxn];
map<LL,int> mp;

LL N,X,M;




int main()
{
    cin >> N >> X >> M;
    sum[0] = 0;

    LL ans = -1;

    _rep(i,1,N){
        sum[i] = X + sum[i-1];
        if( mp.count(X) && N > 1e5){
            int loop = i - mp[X];
            ans = 0;
            LL sumone = sum[i] - sum[mp[X]];

            ans += sum[mp[X]-1];

            LL nn = N - (mp[X]-1);

            ans += (nn/loop)*sumone;
            ans += sum[mp[X] + (nn%loop) -1] - sum[mp[X] -1];

            break;
        }else{
            mp[X] = i;
        }

        X = (X * X)%M;

    }

    if(ans == -1){
        ans = sum[N];
    }

    cout << ans << endl;

    return 0;
}
