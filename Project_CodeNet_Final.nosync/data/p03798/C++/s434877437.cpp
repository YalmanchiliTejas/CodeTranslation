#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <iomanip>
#include <set>
#include <unordered_map>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define reps(i,n) for(int i=1,i##_len=(n);i<=i##_len;++i)
#define rrep(i,n) for(int i=((int)((n)-1));i>=0;--i)
#define rreps(i,n) for(int i=((int)(n));i>0;--i)
#define rept(n) for(int ___i___=0,i##_len=(n);___i___<i##_len;++___i___)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define ZERO(a) memset(a,0,sizeof(a))
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define CEIL(x, y) (((x) + (y) - 1) / (y))

// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
#define DUMPOUT cout
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef LOCAL_
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define dump(...)
#endif

typedef long long int lli;
typedef pair<int, int> ii;
typedef priority_queue<int, vector<int>, greater<int> > heapq;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

signed main() {
    int N; cin >> N;
    string s; cin >> s;

    char s12[4][2] = {
        {'W', 'S',},
        {'S', 'S',},
        {'S', 'W',},
        {'W', 'W',},
    };

    rep(i, 4) {
        string animals(N, 'n');
        animals[N - 1] = s12[i][0];
        animals[0] = s12[i][1];

        bool success = true;
        rep(j, N) {
            int pj = (j - 1 + N) % N, nj = (j + 1 + N) % N;
            if (s[j] == 'o') {
                if (animals[j] == 'S') {
                    if (animals[nj] == 'n') {
                        animals[nj] = animals[pj];
                    } else if (animals[pj] != animals[nj]) {
                        success = false;
                        break;
                    }
                } else {
                    if (animals[nj] == 'n') {
                        animals[nj] = animals[pj] == 'S' ? 'W' : 'S';
                    } else if (animals[pj] == animals[nj]) {
                        success = false;
                        break;
                    }
                }
            } else {
                if (animals[j] == 'W') {
                    if (animals[nj] == 'n') {
                        animals[nj] = animals[pj];
                    } else if (animals[pj] != animals[nj]) {
                        success = false;
                        break;
                    }
                } else {
                    if (animals[nj] == 'n') {
                        animals[nj] = animals[pj] == 'S' ? 'W' : 'S';
                    } else if (animals[pj] == animals[nj]) {
                        success = false;
                        break;
                    }
                }
            }
        }
        if (success) {
            cout << animals << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
