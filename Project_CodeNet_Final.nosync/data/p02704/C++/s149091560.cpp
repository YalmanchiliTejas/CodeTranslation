#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...)name
#define _rep(i,n)repi(i,0,n)
#define repi(i,a,b)for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x)x
#define rep(...)MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c)c.begin(),c.end()
#define write(x)cout<<(x)<<'\n'
using namespace std; using ll = long long; template<class T>using vv = vector<vector<T>>;
template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<int> S(N), T(N);
    vector<ull> U(N), V(N);
    rep(i, N) cin >> S[i];
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> U[i];
    rep(i, N) cin >> V[i];

    vv<ull> A = vvec(N, N, (ull)0);

    vv<bool> Abit = vvec(N, N, false);
    vector<bool> Ubit(N), Vbit(N);
    vector<int> uexist, vexist;
    vector<bool> uundet, vundet;
    vector<int> iuundet, ivundet;
    rep(b, 64) {
        rep(i, N) Ubit[i] = U[i] >> b & 1;
        rep(i, N) Vbit[i] = V[i] >> b & 1;
        uexist.assign(N, 0);
        vexist.assign(N, 0);
        uundet.assign(N, false);
        vundet.assign(N, false);

        rep(h, N) rep(w, N) {
            if ((!S[h] && Ubit[h] && T[w] && !Vbit[w]) || (S[h] && !Ubit[h] && !T[w] && Vbit[w])) {
                write(-1);
                return 0;
            }
            else if ((!S[h] && Ubit[h]) || (!T[w] && Vbit[w])) {
                Abit[h][w] = 1;
                uexist[h] |= 1 << 1;
                vexist[w] |= 1 << 1;
            }
            else if ((S[h] && !Ubit[h]) || (T[w] && !Vbit[w])) {
                Abit[h][w] = 0;
                uexist[h] |= 1 << 0;
                vexist[w] |= 1 << 0;
            }
            else {
                uundet[h] = vundet[w] = true;
            }
        }

        iuundet.clear();
        ivundet.clear();
        rep(i, N) if (uundet[i]) iuundet.push_back(i);
        rep(i, N) if (vundet[i]) ivundet.push_back(i);

        int X = iuundet.size(), Y = ivundet.size();
        bool uall0f = all_of(all(iuundet), [&](int i) { return !Ubit[i]; });
        bool uall1f = all_of(all(iuundet), [&](int i) { return Ubit[i]; });
        bool vall0f = all_of(all(ivundet), [&](int i) { return !Vbit[i]; });
        bool vall1f = all_of(all(ivundet), [&](int i) { return Vbit[i]; });
        bool uall0 = all_of(all(iuundet), [&](int i) { return !Ubit[i] && (uexist[i] >> 0 & 1) == 0; });
        bool uall1 = all_of(all(iuundet), [&](int i) { return Ubit[i] && (uexist[i] >> 1 & 1) == 0; });
        bool vall0 = all_of(all(ivundet), [&](int i) { return !Vbit[i] && (vexist[i] >> 0 & 1) == 0; });
        bool vall1 = all_of(all(ivundet), [&](int i) { return Vbit[i] && (vexist[i] >> 1 & 1) == 0; });

        if (X == 0) {
            rep(h, N) {
                bool b;
                if (!S[h]) {
                    b = 1;
                    rep(w, N) b = b & Abit[h][w];
                }
                else {
                    b = 0;
                    rep(w, N) b = b | Abit[h][w];
                }
                if (b != Ubit[h]) {
                    write(-1);
                    return 0;
                }
            }
            rep(w, N) {
                bool b;
                if (!T[w]) {
                    b = 1;
                    rep(h, N) b = b & Abit[h][w];
                }
                else {
                    b = 0;
                    rep(h, N) b = b | Abit[h][w];
                }
                if (b != Vbit[w]) {
                    write(-1);
                    return 0;
                }
            }
        }
        else if (X != 1 && Y != 1) {
            rep(h, X) rep(w, Y) {
                Abit[iuundet[h]][ivundet[w]] = (h % min(X, Y)) == (w % min(X, Y));
            }
        }
        else if ((uall0 && vall1) || (uall1 && vall0)) {
            write(-1);
            return 0;
        }
        else if (X == 1) {
            if (uall0) {
                for (int h : iuundet) for (int w : ivundet) {
                    Abit[h][w] = vall1f && (vexist[w] >> 1) == 1 ? 0 : Vbit[w];
                }
            }
            else if (uall1) {
                for (int h : iuundet) for (int w : ivundet) {
                    Abit[h][w] = vall0f && (vexist[w] >> 0) == 1 ? 1 : Vbit[w];
                }
            }
            else {
                for (int h : iuundet) for (int w : ivundet) {
                    Abit[h][w] = Vbit[w];
                }
            }
        }
        else {
            if (vall0) {
                for (int h : iuundet) for (int w : ivundet) {
                    Abit[h][w] = uall1f && (uexist[h] >> 1) == 1 ? 0 : Ubit[h];
                }
            }
            else if (vall1) {
                for (int h : iuundet) for (int w : ivundet) {
                    Abit[h][w] = uall0f && (uexist[h] >> 0) == 1 ? 1 : Ubit[h];
                }
            }
            else {
                for (int h : iuundet) for (int w : ivundet) {
                    Abit[h][w] = Ubit[h];
                }
            }
        }

        rep(i, N) rep(j, N) {
            A[i][j] |= (ull)Abit[i][j] << b;
        }
    }

    rep(i, N) {
        rep(j, N) cout << A[i][j] << (j == N - 1 ? "\n" : " ");
    }
}