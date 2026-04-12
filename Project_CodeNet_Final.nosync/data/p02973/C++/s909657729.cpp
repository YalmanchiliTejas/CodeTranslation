#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#define int long long

template <class T>
bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template <class T>
bool chmax(T &a, const T &b) {if (a < b){ a = b; return 1;} return 0;}
template <class T>
bool chmin(T &a, const T &b) {if (a > b){ a = b; return 1;}return 0;}
template <class T>
void printv(vector<T> v) {for (T t : v) {cout << t << " ";}cout << '\n';}

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int a;
    deque<int> v;
    REP(_,N) {
        //cout << "v: " ; printv(v);
        cin >> a;
        int p = distance(v.begin(), lower_bound(ALL(v), a));   
        //cout << "p: " << p << endl;
        //cout << "a: " << a << endl;
        //cout << endl;
        if (p == 0) {
            v.emplace_front(a);
        } else {
            v[p-1] = a;
        }
    }
    
    cout << v.size() << endl;

    return 0;
}
