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

struct Solver {
    string K;
    int D;
    int len;

    vector< vector<long long> > dp;

    void addSelf(long long& a, long long b) {
        a += b;

        if (a >= modulo) {
            a -= modulo;
        }
    }

    long long solve(string& _K, int _D) {
        K = _K;
        D = _D;
        len = size(K);
        dp.resize(D, vector<long long> (2, 0));

        // dp[sum][chosen_smaller] = the number of ways to choose digits so far such that the sum of digits
        // modulo D is `sum` and `chosen_smaller` says whether we already chose some digit smaller than the
        // corresponding digit in K.
        dp[0][0] = 1;

        for (int where = 0; where < len; ++where) {
            vector< vector<long long> > curr(D, vector<long long> (2, 0));

            for (int sum = 0; sum < D; ++sum) {
                for (bool chosen_smaller : {false, true}) {
                    for (int digit = 0; digit < 10; ++digit) {
                        if (digit > K[where] - '0' && !chosen_smaller) {
                            break;
                        }

                        int newSum = (sum + digit) % D;

                        addSelf(curr[newSum][chosen_smaller || (digit < K[where] - '0')], dp[sum][chosen_smaller]);
                    }
                }
            }

            dp = curr;
        }

        long long answer = (dp[0][true] + dp[0][false] - 1) % modulo;

        if (answer < 0) {
            answer += modulo;
        }

        return answer;
    }
};

int main()
{
    int nTest = 1;

    for (int test = 1; test <= nTest; ++test) {
        string K = readString();
        int D = readInt();
        Solver solver;

        cout << solver.solve(K, D) << endl;
    }

    return 0;
}

// Powered by PhoenixAI
