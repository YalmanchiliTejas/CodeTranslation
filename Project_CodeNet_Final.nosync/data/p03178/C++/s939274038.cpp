#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define int ll
//#define int __int128
//#define ll __int128
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cerr << (#x) << " = " << (x) << endl;

const double PI = 2 * acos(0.0);
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";

template <class T0, class T1>
inline ostream & operator << (ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template <class T0, class T1, class T2>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template <class T0, class T1, class T2, class T3>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " <<  get<3>(a) << "}";
}

template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}

void smain();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef RUS_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cout << setprecision(12) << fixed;
    smain();
#ifdef RUS_HOME
    cout << "\n\nTOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
}

vvi dp(100, vi(2)), fp(100, vi(2));

void smain() {

    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    s += '#';
    reverse(ALL(s));
    n++;
    int M = 1e9 + 7;
    int sum = 0;
    dp[0][0] = 1;
    int kek = 0;
    for (int i = 1; i < n; i++) {
        int u = s[i] - '0';
        vi h(10);
        for (int k = 1; k < 10; k++) {
            //kek
            for (int j = 0; j < d; j++) {
                int sm = j + k;
                sm %= d;
                if (k < u) {
                    fp[sm][0] = (fp[sm][0] + dp[j][0] + dp[j][1]) % M;
                } else if (k == u) {
                    fp[sm][0] = (fp[sm][0] + dp[j][0]) % M;
                    fp[sm][1] = (fp[sm][1] + dp[j][1]) % M;
                } else {
                    fp[sm][1] = (fp[sm][1] + dp[j][0] + dp[j][1]) % M;
                }
            }
        }
//        watch(fp);

        sum = (sum + fp[0][0] + kek) % M;
        kek = fp[0][1];
        for (int j = 0; j < d; j++) {
            int sm = j;
            sm %= d;
            if (0 < u) {
                fp[sm][0] = (fp[sm][0] + dp[j][0] + dp[j][1]) % M;
            } else if (0 == u) {
                fp[sm][0] = (fp[sm][0] + dp[j][0]) % M;
                fp[sm][1] = (fp[sm][1] + dp[j][1]) % M;
            }
        }

        dp = fp;
        for (int i = 0; i < d; i++) {
            fp[i][0] = 0;
            fp[i][1] = 0;
        }
    }

    cout << sum;



}