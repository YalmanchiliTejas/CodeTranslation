#include <bits/stdc++.h>
#define int long long
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, a, n) &((x)[a]), &((x)[n])
#define ADD(a, b) ((((a+MOD)%MOD)+((b+MOD)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define PI (acos(-1))
#define EPS (1e-10)
#define INF LLONG_MAX
#define MOD 1000000007
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using SI = std::set<int>;
using MII = std::map<int, int>;
using TIII = std::tuple<int, int, int>;
using MCI = std::map<char, int>;
using VPII = std::vector<PII>;
using Complex = std::complex<double>;
using namespace std;


int A, B, C, X, Y;


signed main(){
    cin >> A >> B >> C >> X >> Y;

    int ans;
    if(2*C <= A+B) ans = 2*C*min(X, Y);
    else ans = (A+B)*min(X, Y);

    if(Y <= X)
        if(2*C <= A) ans += 2*C*(X-Y);
        else ans += A*(X-Y);
    else if(2*C <= B) ans += 2*C*(Y-X);
    else ans += B*(Y-X);

    cout << ans << endl;

    return 0;
}