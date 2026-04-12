#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)


typedef long long ll;
#define INF 1LL<<60
#ifdef _MSC_VER
inline unsigned int __builtin_clz(unsigned int x) { unsigned long r; _BitScanReverse(&r, x); return 31 - r; }
inline int __lg(int __n) { return sizeof(int) * 8 - 1 - __builtin_clz(__n); }
#endif
template<class T> struct IRMXQ {
    vector<T> A; vector<vector<int> > M, X; int N;
    IRMXQ() {}
    IRMXQ(const vector<T> &A_) : A(A_) {
        N = A.size(); int LOGN = __lg(N) + 1;
        M.resize(LOGN); X.resize(LOGN);
        for (int i = 0; i<LOGN; i++) { M[i].resize(N); X[i].resize(N); }
        for (int j = 0; j<N; j++) M[0][j] = X[0][j] = j;
        for (int i = 0; i<LOGN - 1; i++) {
            for (int j = 0; j + (1 << i)<N; j++) {
                if (A[M[i][j + (1 << i)]] < A[M[i][j]]) M[i + 1][j] = M[i][j + (1 << i)];
                else M[i + 1][j] = M[i][j];
                if (A[X[i][j]] < A[X[i][j + (1 << i)]]) X[i + 1][j] = X[i][j + (1 << i)];
                else X[i + 1][j] = X[i][j];
            }
        }
    }
    // 全て[l,r)
    T min_v(int l, int r) { return A[min_i(l, r)]; }
    int min_i(int l, int r) {
        r = min(N, r);
        int d = __lg(r - l);
        if (A[M[d][r - (1 << d)]] < A[M[d][l]]) return M[d][r - (1 << d)];
        else return M[d][l];
    }
    T max_v(int l, int r) { return A[max_i(l, r)]; }
    int max_i(int l, int r) {
        r = min(N, r);
        int d = __lg(r - l);
        if (A[X[d][l]] < A[X[d][r - (1 << d)]]) return X[d][r - (1 << d)];
        else return X[d][l];
    }
};
//-----------------------------------------------------------------------------------
int N, X[201010], Y[201010];
//-----------------------------------------------------------------------------------
int R[201010], B[201010];
ll solve1() {
    rep(i, 0, N) {
        R[i] = (min(X[i], Y[i]));
        B[i] = (max(X[i], Y[i]));
    }
    sort(R, R + N);
    sort(B, B + N);

    return 1LL * (R[N - 1] - R[0]) * (B[N - 1] - B[0]);
}
//-----------------------------------------------------------------------------------
pair<int, int> XY[201010];
ll solve2() {
    rep(i, 0, N) XY[i] = { min(X[i], Y[i]), max(X[i], Y[i]) };
    sort(XY, XY + N);

    vector<int> r, b;
    rep(i, 0, N) r.push_back(XY[i].first);
    rep(i, 0, N) b.push_back(XY[i].second);

    IRMXQ<int> rseg(r);
    IRMXQ<int> bseg(b);

    ll ans = INF;
    rep(i, 1, N) {
        int Rmax = max(rseg.max_v(0, i), bseg.max_v(i, N));
        int Rmin = min(rseg.min_v(0, i), bseg.min_v(i, N));
        int Bmax = max(bseg.max_v(0, i), rseg.max_v(i, N));
        int Bmin = min(bseg.min_v(0, i), rseg.min_v(i, N));

        ll a = 1LL * (Rmax - Rmin) * (Bmax - Bmin);
        ans = min(ans, a);
    }
    return ans;
}
//-----------------------------------------------------------------------------------
int main() {
    cin >> N;
    rep(i, 0, N) scanf("%d%d", &X[i], &Y[i]);

    cout << min(solve1(), solve2()) << endl;
}