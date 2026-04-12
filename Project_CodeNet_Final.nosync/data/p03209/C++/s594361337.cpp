#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;


typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

ll a[51] = {0};
ll p[51] = {0};

ll solve(ll N, ll X){
    if(N == 0 && X == 1) return 1;
    if(X == 1) return 0;
    if(1 < X && X <= (1 + a[N-1])) return solve(N-1, X-1);
    if(X == (2 + a[N-1])) return p[N-1] + 1;
    if(X > (2 + a[N-1]) && X <= (2 + 2 * a[N-1])){
        return p[N-1] + 1 + solve(N-1, X-2-a[N-1]);
    }
    else{
        return 2 * p[N-1] + 1;
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    ll N, X;
    cin >> N >> X;

    a[0] = 1;
    p[0] = 1;
    FOR(i,1,51){
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }

    cout << solve(N,X) << endl;
    return 0;
}