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

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }



signed main(){

    int N, Q; cin >> N >> Q;
    vec A(Q), B(Q);
    REP(i, Q){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    vec p(N);
    REP(i, N) p[i] = i;
    vector<bool> f(N, false);
    f[0] = true;
    f[1] = true;

    int b = 0;
    REP(i, Q){
        swap(p[A[i]], p[B[i]]);
        if(p[A[i]] == 0) b = A[i];
        else if(p[B[i]] == 0) b = B[i];
        if(b > 0) f[p[b - 1]] = true;
        if(b < N - 1) f[p[b + 1]] = true;
    }
    int ans = 0;
    REP(i, N) if(f[i]) ans++;
    cout << ans << endl;
    
    return 0;
}