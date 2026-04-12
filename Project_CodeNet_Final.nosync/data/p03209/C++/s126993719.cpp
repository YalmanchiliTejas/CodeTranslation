#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[0].size()){ cout << m[i][j] << ","; } cout << endl; }}



signed main(){

    int N, X; cin >> N >> X;
    vec P(N + 1);
    P[0] = 1;
    REP(i, N) P[i + 1] = 2 * P[i] + 1;
    vec T(N + 1);
    T[0] = 1;
    REP(i, N) T[i + 1] = 2 * T[i] + 3;

    int ans = 0;
    int x = X, n = N;
    while(x > 0){
        while(T[n] > x){
            n--;
            x--;
            if(x == 0){
                cout << ans;
                return 0;
            }
        }
        x -= T[n];
        ans += P[n];
        if(x >= 1){
            ans += 1;
            x--;
        }
    }
    cout << ans;
    
    return 0;
}