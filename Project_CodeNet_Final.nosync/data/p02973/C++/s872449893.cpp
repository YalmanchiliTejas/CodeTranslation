#include <bits/stdc++.h>
#define int long long
#define rep(i, a, n) for(int i = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int i = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int i = (int)(a);(x);++(i))
#define repr(i, a, n) for(int i = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int i = (int)(a);(i) >= (int)(n);--(i))
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RNG(x, a, n) &((x)[a]), &((x)[n])
#define ADD(a, b) (((a%MOD+MOD)%MOD+(b%MOD+MOD)%MOD)%MOD)
#define SUB(a, b) (((a%MOD+MOD)%MOD-(b%MOD+MOD)%MOD+MOD)%MOD)
#define MUL(a, b) ((((a%MOD+MOD)%MOD)*((b%MOD+MOD)%MOD))%MOD)
#define CHADD(a, b) (a = ADD(a, b))
#define CHMUL(a, b) (a = MUL(a, b))
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) (x/gcd(x,y)*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define PI (acos(-1))
#define EPS (1e-10)
#define INF LLONG_MAX
#define MOD 1000000007LL
using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using Complex = complex<double>;
template<typename T, template<typename> typename C = less> using PQ = priority_queue<T, vector<T>, C<T>>;
template<typename T> bool chmax(T& a, const T& b){ if(a<b){ a=b; return true; } return false; }
template<typename T> bool chmin(T& a, const T& b){ if(a>b){ a=b; return true; } return false; }
template<typename I> int ACC(I f, I l, int i){ return accumulate(f, l, i); }
 

int N;
int A[100010];
int l[100010];


signed main(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    fill(RNG(l, 0, N), -1);

    int ans = 1;
    rep(i, 0, N){
        int p = lb(RNG(l, 0, ans), A[i], [](int a, int b){ return a >= b; })-&l[0];
        l[p] = A[i];
        if(p == ans) ans++;
    }

    cout << ans << endl;

    return 0;
}