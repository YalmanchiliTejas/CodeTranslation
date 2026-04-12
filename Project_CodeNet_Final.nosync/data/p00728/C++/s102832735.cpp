#include <bits/stdc++.h>
#define int long long
#define double long double
#define rep(i, a, n) for(int i = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int i = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int i = (int)(a);(x);++(i))
#define repr(i, a, n) for(int i = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int i = (int)(a);(i) >= (int)(n);--(i))
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), end(x))
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) ((x)/gcd(x,y)*(y))
#define isin(x, l, r) ((l) <= (x) and (x) < (r))
#define fcout(n) cout << fixed << setprecision(n)
#define rcout(n) cout << right << setw(n)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define PI (acosl(-1))
#define EPS (1e-10)
#define INF LLONG_MAX
#define INF32 INT32_MAX
#define MOD 1000000007LL
using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;
using TIII = tuple<int, int, int>;
using VPII = vector<PII>;
using VTIII = vector<TIII>;
using Complex = complex<double>;
template<typename T, template<typename> typename C = less> using PQ = priority_queue<T, vector<T>, C<T>>;
template<typename T> bool chmax(T& a, const T& b, bool t = false){ if(a<b or (t and a == b)){ a=b; return true; } return false; }
template<typename T> bool chmin(T& a, const T& b, bool t = false){ if(a>b or (t and a == b)){ a=b; return true; } return false; }


int n;
int s[110];


signed main(){
    while(cin >> n, n > 0){
        rep(i, 0, n) cin >> s[i];
        int a = accumulate(s, s+n, 0LL);
        a -= *max_element(s, s+n);
        a -= *min_element(s, s+n);
        cout << a/(n-2) << endl;
    }

    return 0;
}
