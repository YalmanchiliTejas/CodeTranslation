#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define rep1(i,n) for (int i = 1; i <= int(n); i++)
#define repR(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = int(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define cauto const auto
#ifdef LOCAL
#define dump(...) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] ", my_dmp(#__VA_ARGS__, __VA_ARGS__)
void my_dmp(const char*) { cerr << endl; }
template <class T, class... U>
void my_dmp(const char *s, T const& x, U const& ...y) { const char *o = "({[", *e = "]})"; for (int i = 0; *s != '\0'; cerr << *s++) { if (count(o,o+3,*s)) i++; if (count(e,e+3,*s)) i--; if (!i && *s == ',') break; } cerr << " = " << x; if (*s == ',') cerr << ", ", s++; my_dmp(s, y...); }
#else
#define dump(...)
#endif
using ll = long long;
#define int ll
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
#define OUTPUT(...) ostream& operator<<(ostream& os, __VA_ARGS__ const& v) { os << "{"; for (auto const& x : v) os << " " << x; return os << " }"; }
template <class T> OUTPUT(vector<T>)
template <class T> OUTPUT(deque<T>)
template <class T> OUTPUT(set<T>)
template <class T> OUTPUT(multiset<T>)
template <class T, class U> OUTPUT(map<T,U>)
#undef OUTPUT
template <class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct my_Init { my_Init() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); } } my_init;

template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
////////////////////////////////

int32_t main() {
    int n; cin >> n;
    vector<int> s(n); cin >> s;

    int ma = 0;
    loop (ab,1,<n) {
        int sum = 0, i = 0, j = n-1;
        for ( ; i+ab < n-1; i += ab, j -= ab) {
            if ((n-1)%ab == 0 && i >= j) break;
            sum += s[i] + s[j];
            chmax(ma,sum);
        }
    }
    cout << ma << "\n";
}
