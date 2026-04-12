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
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

template<class T> using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// MACROS_BEGIN
#define CLEAR() cerr << endl;
#define LET(x, a) __typeof(a) x = a
#define FOREACH(it, v) for (LET(it, (v).begin()); it != (v).end(); ++it)
#define REPEAT(i, n) for (int i = 0; i < (n); ++i)
// MACROS_END

// GENERIC_UTILITIES_BEGIN
// template <class T> inline int size(const T& c) {return (int) c.size();}
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
#define DEBUG(...) __f(__LINE__, #__VA_ARGS__, __VA_ARGS__)

template<typename Arg> void __print(const string& name, Arg&& arg) {
    cerr << "[" << name << ": " << arg << "]" << " ";
}

void __printLine(int line) {
    cerr << "LINE " << line << ": ";
    cerr << boolalpha;    
}

template<typename Arg> void __g(vector<string>& names, int idx, Arg&& arg) {
    __print(names[idx], arg);
}

template<typename Arg, typename... Args> void __g(vector<string>& names, int idx, Arg&& arg, Args&&... args) {
    __g(names, idx, arg); __g(names, idx + 1, args...);
}

template <typename Arg> void __f(int line, const string& name, Arg&& arg) {
    __printLine(line);
    __print(name, arg); CLEAR();
}

template <typename Arg, typename... Args> void __f(int line, const string& _names, Arg&& arg, Args&&... args) {
    __printLine(line);
    vector<string> names = split(_names, ", "); __g(names, 0, arg, args...); CLEAR();
}
#else
#define DEBUG(...)
#endif
// DEBUGGING_UTILITIES_END

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double epsilon = 1e-8;
const int infinite    = 2000000000; // 2 * 10^9
const long long infiniteLL = 2000000000000000000LL; // 2 * 10^18
const long long modulo = 1000000007;

template <int MOD_> struct ModInt {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;

    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:

    ModInt() : v(0) {}
    ModInt(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const ModInt& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, ModInt& n) { ll v_; in >> v_; n = ModInt(v_); return in; }

    friend bool operator == (const ModInt& a, const ModInt& b) { return a.v == b.v; }
    friend bool operator != (const ModInt& a, const ModInt& b) { return a.v != b.v; }

    ModInt inv() const {
        ModInt res;
        res.v = minv(v, MOD);
        return res;
    }

    friend ModInt inv(const ModInt& m) {
        return m.inv();
    }

    ModInt neg() const {
        ModInt res;
        res.v = v ? MOD - v : 0;
        return res;
    }

    friend ModInt neg(const ModInt& m) {
        return m.neg();
    }

    ModInt operator- () const {
        return neg();
    }

    ModInt operator+ () const {
        return ModInt(*this);
    }

    ModInt& operator ++ () {
        v++;

        if (v == MOD) {
            v = 0;
        }

        return *this;
    }

    ModInt& operator -- () {
        if (v == 0) {
            v = MOD;
        }

        v--;
        return *this;
    }

    ModInt& operator += (const ModInt& o) {
        v += o.v;

        if (v >= MOD) {
            v -= MOD;
        }

        return *this;
    }

    ModInt& operator -= (const ModInt& o) {
        v -= o.v;

        if (v < 0) {
            v += MOD;
        }

        return *this;
    }

    ModInt& operator *= (const ModInt& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }

    ModInt& operator /= (const ModInt& o) {
        return *this *= o.inv();
    }

    friend ModInt operator ++ (ModInt& a, int) { ModInt r = a; ++a; return r; }
    friend ModInt operator -- (ModInt& a, int) { ModInt r = a; --a; return r; }
    friend ModInt operator + (const ModInt& a, const ModInt& b) { return ModInt(a) += b; }
    friend ModInt operator - (const ModInt& a, const ModInt& b) { return ModInt(a) -= b; }
    friend ModInt operator * (const ModInt& a, const ModInt& b) { return ModInt(a) *= b; }
    friend ModInt operator / (const ModInt& a, const ModInt& b) { return ModInt(a) /= b; }
};

struct Task {
    int N;
    vector< ModInt<modulo> > v;
    ModInt<modulo> sum;

    void readInput() {
        N = readInt();
        v.resize(N);
        sum = 0;

        for (int i = 0; i < N; ++i) {
            v[i] = readInt();
            sum += v[i];
        }

        sum *= sum;

        for (int i = 0; i < N; ++i) {
            sum -= v[i] * v[i];
        }

        sum /= 2;

        printf("%d\n", sum);
    }

    void solve() {

    }

    void perform() {
        readInput();
        solve();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Task task;
    task.perform();

    return 0;
}

// Powered by PhoenixAI
