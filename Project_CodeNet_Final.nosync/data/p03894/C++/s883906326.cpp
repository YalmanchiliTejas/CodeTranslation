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
    REP(i, Q) swap(p[A[i]], p[B[i]]);
    int b = -1;
    vec invp(N);
    REP(i, N) invp[p[i]] = i;
    REP(i, N) if(p[i] == 0) b = i;

    vector<bool> f(N, false);
    f[b] = true;
    if(b > 0) f[b - 1] = true;
    if(b < N - 1) f[b + 1] = true;
    IREP(i, Q){
        swap(p[A[i]], p[B[i]]);
        if(A[i] == b) b = B[i];
        else if(B[i] == b) b = A[i];
        if(b > 0) f[invp[p[b - 1]]] = true;
        if(b < N - 1) f[invp[p[b + 1]]] = true;
    }
    int ans = 0;
    REP(i, N) if(f[i]) ans++;
    cout << ans << endl;
    
    return 0;
}