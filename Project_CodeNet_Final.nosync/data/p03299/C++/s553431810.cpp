#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(auto i##0_to = (t), i = decltype(t)(f); i <= i##0_to; i++)
#define uptil(f, t, i)   for(auto i##0_to = (t), i = decltype(t)(f); i <  i##0_to; i++)
#define downto(f, t, i)  for(auto i##0_to = decltype(f)(t), i = (f); i >= i##0_to; i--)
#define downtil(f, t, i) for(auto i##0_to = decltype(f)(t), i = (f); i >  i##0_to; i--)
using LD = long double;
#define double LD
#define long long long
#define LL long
#define int long
template<class T> using vec = vector<T>;
using VB = vec<bool>;   using WB = vec<VB>;
using VC = vec<char>;   using WC = vec<VC>;
using VI = vec<int>;    using WI = vec<VI>;
using VD = vec<double>; using WD = vec<VD>;
using VS = vec<string>; using WS = vec<VS>;
using PI = pair<int, int>;  using VPI = vec<PI>; using WPI = vec<VPI>;
using MI = map<int, int>;   using VMI = vec<MI>;

#if defined(EBUG) && !defined(ONLINE_JUDGE)
    #define debug true
    #define _GLIBCXX_DEBUG
    #define _LIBCPP_DEBUG 2
    #define _LIBCPP_DEBUG2 2
    #define ln << endl
    #define dd(x) cerr << #x << " = " << (x) << ", "
    #define ddd(x) cerr << #x << " = " << (x) ln
#else
    #define debug false
    #define ln << '\n'
    #define dd(x) cerr
    #define ddd(x) cerr
#endif
#define tb << '\t'
#define sp << ' '
#define db dd
#define dbg ddd

template<class T>          inline istream& operator>>(istream& s, vec<T>& v) { for(auto&& p : v) s >> p; return s; }
template<class T, class S> inline ostream& operator<<(ostream&, const pair<T, S>&);
template<class T>          inline ostream& operator<<(ostream&, const vec<T>&);
template<class T, class S> inline ostream& operator<<(ostream&, const map<T, S>&);
#define DEFINE_ITER_OUTPUT(s, x, sep) { int i = 0; for(const auto& x##0_elem : x) { if(i++) s << sep; s << x##0_elem; } return s; }
template<class T, class S> inline ostream& operator<<(ostream& s, const pair<T, S>& p) { return s << "(" << p.first << "," << p.second << ")"; }
template<class T>          inline ostream& operator<<(ostream& s, const vec<T>& v) DEFINE_ITER_OUTPUT(s, v, ' ')
template<class T, class S> inline ostream& operator<<(ostream& s, const map<T, S>& m) DEFINE_ITER_OUTPUT(s, m, ' ')
template<class T>          inline ostream& operator<<(ostream& s, const vec<vec<T>>& w) DEFINE_ITER_OUTPUT(s, w, '\n')
template<class T, class S> inline ostream& operator<<(ostream& s, const vec<map<T, S>>& vm) DEFINE_ITER_OUTPUT(s, vm, '\n')

void solve();

signed main() {
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(20);

    solve();

    return 0;
}

constexpr int mod = 1e9L + 7;

LL pow_(LL x, signed LL n) {
    LL ans = 1;
    while(n) {
        if(n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}
#define pow pow_

void solve() {
// N N(H)
/* <foxy.memo-area> */
int N;cin>>N;VI H(N);times(N,Ri_0){cin>>H[Ri_0];}
/* </foxy.memo-area> */

    if(N == 1) {
        cout << pow(2, H[0]);
        return;
    }

    VI th(N); int free = 0;

    if(H[0] > H[1]) {
        free += H[0] - H[1];
        H[0] = H[1];
    }
    if(H[0] == 1) {
        ++free;
        H[0] = 0;
    }

    uptil(1, N, i) {
        if(H[i] == 1 || (H[i-1] <= 1 && (i == N-1 || H[i+1] <= 1))) {
            free += H[i];
            H[i] = 0;
        } else if(H[i-1] != 1) {
            th[i] = min(H[i-1], H[i]);
        }
        if(H[i] > H[i-1]) {
            if(i == N-1) {
                free += H[i] - H[i-1];
                H[i] = H[i-1];
            } else {
                if(H[i] > H[i+1]) {
                    free += H[i] - max(H[i-1], H[i+1]);
                    H[i] = max(H[i-1], H[i+1]);
                }
            }
        }
    }
    if(debug) cerr << free ln << H ln << th ln ln;

    map<int, int> thcp;
    vec<int> thzp;
    {
        thzp = th;
        thzp.push_back(0);
        sort(thzp.begin(), thzp.end());
        thzp.erase(unique(thzp.begin(), thzp.end()), thzp.end());

        times(thzp.size(), i) thcp[thzp[i]] = i;
    }
    int zth = thzp.size();
    if(debug) cerr << thcp ln ln;
    
    VI pyon(zth), qyon;
    int ans = 1;
    rtimes(N, i) {
        qyon = pyon;
        if(H[i] == 0) {
            times(zth, t) pyon[t] = 0;
        } else if(i == N-1 or H[i+1] == 0) {
            times(zth, t) {
                if(thzp[t] > th[i]) {
                    pyon[t] = 0;
                } else if(thzp[t] == th[i]) {
                    pyon[t] = 2;
                } else {
                    pyon[t] = 1;
                }
            }
        } else if(i == 0 or H[i-1] == 0) {
            // leftmost
            assert(th[i] == 0);

            int a = qyon[thcp[ th[i+1] ]] % mod;
            int g = 1;
            downto(thcp[ th[i+1] ]-1, 0, s) {
                int e = th[i+1] - thzp[s];
                if(s == 0) e -= 1;
                a += qyon[s] * (pow(2, e) - g) % mod;
                a %= mod;
                if(debug) {
                    cerr << qyon[s] << " * (2^" << e << " - " << g << ") * 2;" tb;
                }
                g = pow(2, e);
            }

            a *= 2;
            a %= mod;
            ans *= a;
            ans %= mod;
            if(debug) {
                cerr ln << "a: " << a << ", ans: " << ans ln;
            }
            times(zth, t) pyon[t] = 0;
        } else if(th[i] > th[i+1]) {
            assert(H[i] == th[i]);
            times(zth, t) {
                if(thzp[t] > th[i]) {
                    pyon[t] = 0;
                } else if(thzp[t] == th[i]) {
                    pyon[t] = qyon[thcp[th[i+1]]] * 2 % mod;
                } else {
                    pyon[t] = qyon[ min(t, thcp[th[i+1]]) ];
                }
            }
        } else if(th[i] == th[i+1]) {
            times(zth, t) {
                if(thzp[t] > th[i]) {
                    pyon[t] = 0;
                } else if(thzp[t] == th[i]) {
                    pyon[t] = qyon[t] * 2 % mod;
                } else {
                    pyon[t] = qyon[t];
                }
            }
        } else {
            assert(H[i] == th[i+1]);
            times(zth, t) {
                if(thzp[t] > th[i]) {
                    pyon[t] = 0;
                } else if(thzp[t] == th[i]) {
                    pyon[t] = qyon[thcp[ th[i+1] ]];
                    int g = 1;
                    downto(thcp[ th[i+1] ]-1, thcp[ th[i] ], s) {
                        int e = th[i+1] - thzp[s];
                        pyon[t] += qyon[s] * (pow(2, e) - g);
                        pyon[t] %= mod;
                        if(debug) {
                            cerr << qyon[s] << " * (2^" << e << " - " << g << ") * 2;" tb;
                        }
                        g = pow(2, e);
                    }
                    if(debug) cerr ln;
                    pyon[t] *= 2;
                    pyon[t] %= mod;
                } else {
                    pyon[t] = qyon[t] * pow(2, H[i] - th[i]) % mod;
                }
            }
        }
        if(debug) {
            cerr << i << ": " << H[i] sp << th[i] ln << pyon ln ln;
        }
    }
    if(debug) cerr << ans ln;
    ans *= pow(2, free);
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans ln;
}
