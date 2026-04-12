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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define fcout cout << fixed << setprecision(10)
#define rcout(n) cout << right << setw(n)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define PI (acos(-1))
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


int N, X;
map<PII, int> mem;


int S(int L){
    return (1LL<<(L+2))-3;
}


int rec(int k = N, int x = X){
    if(mem.find({ k, x }) != end(mem)) return mem[{ k, x }];
    int& res = mem[{ k, x }];
    if(x == 0) return res = 0;
    if(k == 0) return res = 1;
    if(x <= 1+S(k-1)) return res = rec(k-1, x-1);
    if(x <= 1+S(k-1)+1) return res = rec(k-1, S(k-1))+1;
    return res = rec(k-1, S(k-1))+1+rec(k-1, x-(1+S(k-1)+1));
}


signed main(){
    cin >> N >> X;

    cout << rec() << endl;

    return 0;
}