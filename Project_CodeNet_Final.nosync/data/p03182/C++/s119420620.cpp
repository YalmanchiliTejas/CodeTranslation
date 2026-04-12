#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

// MACROS_BEGIN
#define CLEAR() cerr << endl;
#define LET(x, a) __typeof(a) x = a
#define FOREACH(it, v) for (LET(it, (v).begin()); it != (v).end(); ++it)
#define REPEAT(i, n) for (int i = 0; i < (n); ++i)
// MACROS_END

// GENERIC_UTILITIES_BEGIN
template <class T> inline int size(const T& c) {return (int) c.size();}
inline long long two(int x) {return (1LL << (x));}

vector<string> split(string s, string delim) {
    s += delim[0];
    string tmp;
    vector<string> result;
    for (int i = 0; i < size(s); ++i) {
        if (delim.find(s[i]) == string::npos) {
            tmp.push_back(s[i]);
        }
        else {
            if (tmp != "") result.push_back(tmp);
            tmp.clear();
        }
    }
    return result;
}

template <class A, class B> void setMin(A& a, const B& b) {
    a = min(a, b);
}

template <class A, class B> void setMax(A& a, const B& b) {
    a = max(a, b);
}
// GENERIC_UTILITIES_END

// FAST_IO_BEGIN
// FAST_IO_END

// STANDARD_IO_BEGIN
#ifndef USING_FAST_IO
int readInt() {int N = -1; scanf("%d", &N); return N;}
double readDouble() {double D; scanf("%lf", &D); return D;}
string readString() {char buffer[1 << 20]; scanf("%s", buffer); return buffer;}
long long readLongLong() {long long N = -1; scanf("%lld", &N); return N;}
#endif // NOT DEFINED USING_FAST_IO
// STANDARD_IO_END


// OUTPUT_UTILITIES_BEGIN
template <class A, class B> ostream& operator << (ostream& o, const pair<A, B>& p);
template <class T> ostream& operator << (ostream& o, const vector<T>& v);
template <class A, class B> ostream& operator << (ostream& o, const map<A, B>& m);
template <class T> ostream& operator << (ostream& o, const set<T>& s);
template <class T> ostream& operator << (ostream& o, const queue<T>& q);
template <class T> ostream& operator << (ostream& o, const stack<T>& s);

template <class A, class B> ostream& operator << (ostream& o, const pair<A, B>& p) {
    o << "(" << p.first << "," << p.second << ")"; return o;
}

template <class T> ostream& operator << (ostream& o, const vector<T>& v) {
    o << "{"; bool first = true; FOREACH(it, v) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class A, class B> ostream& operator << (ostream& o, const map<A, B>& m) {
    o << "{"; bool first = true; FOREACH(it, m) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const set<T>& s) {
    o << "{"; bool first = true; FOREACH(it, s) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const queue<T>& q) {
    o << "{"; bool first = true; queue<T> p = q; while (!p.empty()) { if (!first) o << ","; first = false; o << p.front(); p.pop(); } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const stack<T>& s) {
    o << "{"; bool first = true; stack<T> r = s; while (!r.empty()) { if (!first) o << ","; first = false; o << r.top(); r.pop(); } return o << "}";
}
// OUTPUT_UTILITIES_END

// DEBUGGING_UTILITIES_BEGIN
// DEBUGGING SWITCH
#define PHOENIX_DEBUG

#ifdef PHOENIX_DEBUG
#define BUG(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;
#else
#define BUG(...)
#endif
// DEBUGGING_UTILITIES_END

const double epsilon = 1e-8;
const int infinite    = 1000000000;
const long long infiniteLL = 1000000000000000000LL;
const long long modulo = 1000000007;

struct Node {
    long long val;
    long long lazy;

    Node() {
        val = lazy = 0;
    }

    void handle(long long pLazy) {
        val += pLazy;
        lazy += pLazy;
    }
};

struct Solver {
    int N, M;
    vector< vector< pair<int, long long>> > intervals;
    vector<Node> tree;

    void initializeTree() {
        tree.resize(4 * N + 4);
    }

    long long query(int low, int high) {
        return query(1, 0, N, low, high);
    }

    long long query(int node, int b, int e, int low, int high) {
        if (b > high || e < low) {
            return -infiniteLL;
        } else if (b >= low && e <= high) {
            return tree[node].val;
        } else {
            int left = 2 * node, right = 2 * node + 1, mid = (b + e) / 2;
            split(tree[node], tree[left], tree[right]);
            return max(query(left, b, mid, low, high), query(right, mid + 1, e, low, high));
        }
    }

    void split(Node& p, Node& u, Node& v) {
        u.handle(p.lazy);
        v.handle(p.lazy);
        p.lazy = 0;
    }

    void merge(Node& p, Node& u, Node& v) {
        p.val = max(u.val, v.val);
    }

    void update(int node, int b, int e, int low, int high, long long val) {
        if (b > high || e < low) {
            return;
        } else if (b >= low && e <= high) {
            tree[node].val += val;
            tree[node].lazy += val;
        } else {
            int left = 2 * node, right = 2 * node + 1, mid = (b + e) / 2;
            split(tree[node], tree[left], tree[right]);
            update(left, b, mid, low, high, val);
            update(right, mid + 1, e, low, high, val);
            merge(tree[node], tree[left], tree[right]);
        }
    }

    void update(int low, int high, long long val) {
        update(1, 0, N, low, high, val);
    }

    void solve() {
        N = readInt(), M = readInt();
        intervals.resize(N + 1);

        for (int i = 0; i < M; ++i) {
            int L = readInt(), R = readInt(), v = readInt();
            intervals[R].push_back(make_pair(L, v));
        }

        initializeTree();

        for (int i = 1; i <= N; ++i) {
            long long maxSoFar = query(0, i - 1);
            update(i, i, maxSoFar);

            for (pair<int, int> p : intervals[i]) {
                int L = p.first, R = i;
                long long v = p.second;
                update(L, R, v);
            }
        }

        long long answer = 0;

        for (int i = 1; i <= N; ++i) {
            answer = max(answer, query(i, i));
        }

        cout << answer << endl;
    }
};

int main()
{
    int nTest = 1;

    for (int test = 1; test <= nTest; ++test) {
        Solver solver;
        solver.solve();
    }

    return 0;
}

// Powered by PhoenixAI
