#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Solve {
public:
    Int N;
    vector<Int> s;
    vector<Int> rui;

    // A + k*(A-B) == N

    void input(Int N_, vector<Int> s_) {
        N = N_;
        N--;
        s.resize(N + 1);
        rui.resize(N + 1);
        s = s_;
    }

    void input() {
        cin >> N;
        N--;
        s.resize(N + 1);
        rui.resize(N + 1);
        for (int i = 0; i <= N; ++i) {
            cin >> s[i];
        }
    }

    Int calc1(Int d) {
        for (int i = N; i >= 0; i -= d) {
            if (i + d > N) {
                rui[i] = s[i];
            } else {
                rui[i] = rui[i + d] + s[i];
            }
        }
        for (int i = N / d * d; i >= 0; i -= d) {
            if (i + d > N) {
                rui[i] = s[i];
            } else {
                rui[i] = rui[i + d] + s[i];
            }
        }


        auto check = [&](Int A) -> bool {
            if (A <= 0) return false;
            if (A - d <= 0) return false;
//            Int L = max((A - d) / d * 2 + 1, (N - A) / d * 2 + 1);
//            Int R = min((A - d) / d * 2 + 1, (N - A) / d * 2 + 1);
//            return L == R;
//            return (A + d - 1) / d * 2 > (N - A) / d * 2 + 1;
            Int las = N - A;
            if ((las - A) % d == 0 && A <= las) return false;
            return true;
        };

        Int ret = -INFl;
        for (Int A = N % d; A <= N; A += d) {
            if (!check(A)) continue;
            Int B = A - d;
            Int tmp = rui[A] + rui[A - B];
            if (N - A + d <= N) {
                tmp -= rui[N - A + d];
            }
            chmax(ret, tmp);
        }

        return ret;
    }

    Int calc2(Int d) {
        if (N % d) return -INFl;

        for (int i = N; i >= 0; --i) {
            if (i + d > N) {
                rui[i] = s[i];
            } else {
                rui[i] = s[i] + rui[i + d];
            }
        }

//        auto check = [&](Int A) -> bool {
//            Int L = max((A - d) / d * 2 + 1, (N - A) / d * 2 + 1);
//            Int R = min((A - d) / d * 2 + 1, (N - A) / d * 2 + 1);
//            return L >= R;
//        };

        Int ret = -INFl;
        for (Int A = d + 1; A <= N; ++A) {
//            if (!check(A)) continue;
            Int k = N / d;
            Int B = A - d;
            if (k * d + B >= N) {
                continue;
            }


            Int tmp = rui[A] + rui[A - B];
            if (k * (A - B) + A <= N) {
                tmp -= rui[k * (A - B) + A];
            }
            chmax(ret, tmp);

        }
        return ret;
    }

    Int fool() {
        Int ret = -INFl;
        Int bA, bB;
        for (Int A = 2; A <= N; ++A) {
            for (Int B = 1; B < A; ++B) {
                Int tmp = 0;
                set<Int> u;
                Int idx = 0;
                while (true) {
                    idx += A;
                    if (u.count(idx)) break;
                    u.insert(idx);
                    tmp += s[idx];
                    if (idx >= N) break;

                    idx -= B;
                    if (u.count(idx)) break;
                    u.insert(idx);
                    tmp += s[idx];
                    if (idx >= N) break;
                }
                if (idx == N) {
                    if (ret < tmp) {
                        ret = tmp;
                        bA = A, bB = B;
                    }
                }
            }
        }

        cout << ret << " " << bA << " " << bB << endl;
//        cout << ret << endl;
        return ret;
    }

    Int solve() {
//        input();

//        fool();


        Int ans = -INFl;
        for (int d = 1; d < N; ++d) {
            Int tmp = calc1(d);
            chmax(ans, tmp);
            Int tmp2 = calc2(d);
            chmax(ans, tmp2);
        }

        cout << ans << endl;
        return ans;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    if (true) {
        Solve x;
        x.input();
        x.solve();
    } else {
        while (true) {
            Int N = rand() % 1000 + 3;
            vector<Int> s(N);
            Int l = static_cast<Int>(-1e9);
            Int r = static_cast<Int>(1e9);
            for (int i = 0; i < N; ++i) {
                s[i] = rand() % (r - l + 1) + l;
            }
            s.front() = s.back() = 0;

            cout << "-------------" << endl;

            cout << N << endl;
            for (auto e : s) cout << e << " ";

            cout << endl;
            Solve x, y;
            x.input(N, s);
            y.input(N, s);
            if (x.fool() != y.solve()) {
                exit(-1);
            }
        }
    }


    return 0;
}
