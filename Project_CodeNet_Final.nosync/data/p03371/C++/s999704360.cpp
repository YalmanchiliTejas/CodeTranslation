#pragma warning(disable:4996)
#include <regex>
#include <tuple>
#include <sstream>
#include <queue>
#include <map>
#include <numeric>
#include <list>
#include <limits.h>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <float.h>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <chrono>
#include <functional>
using namespace std;
using namespace std::chrono;

#define INITVAL INT_MAX
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,N) FOR(i,0,N)
#define MP(a, b) make_pair(a, b)
#define WHITE first
#define BLACK second
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
#define INPUT(type, name) type name; cin >> name;

#define IN_H(h) (0 <= (h) && (h) < H)
#define IN_W(w) (0 <= (w) && (w) < W)
#define CELL(cell, h, w) (IN_H(h) && IN_W(w) ? cell[h][w] : INT_MAX)

#define BETWEEN(x1, x, x2) (x1 <= x && x < x2)
#define PUSH(x, y) (t[y][x] == 0){q.push(pii(x, y));t[y][x] = 1;}
#define sq(x) ((x)*(x))

#ifdef _MSC_VER
#include <intrin.h>
#include <stdint.h>
#define __builtin_popcount __popcnt
#define __builtin_ctz ctz
#define __builtin_clz clz

static uint32_t inline ctz(uint32_t x)
{
    unsigned long r = 0;
    _BitScanReverse(&r, x);
    return r;
}

static uint32_t inline clz(uint32_t x)
{
    unsigned long r = 0;
    _BitScanForward(&r, x);
    return r;
}

#endif

class Timer
{
public:
    Timer() :start_(system_clock::now()){}
    double elapsed() const
    {
#ifndef TEST
        duration<double> d = system_clock::now() - start_;
        return d.count();
#else
        return 0;
#endif
    }
private:
    system_clock::time_point start_;
};

template<int N>
class UnionFind
{
public:
    UnionFind() :parent(N){ REP(i, N)parent[i] = i; }
    bool isSame(int A, int B){ return root(A) == root(B); }
    void unite(int A, int B)
    {
        A = root(A);
        B = root(B);
        if (A != B)
        {
            parent[B] = A;
        }
    }
private:
    vi parent;
    int root(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return parent[x] = root(parent[x]);
        }
    }
};

template<typename T>
bool isInclude(T l, T v, T r)
{
    return l < v && v < r;
}

template<typename T>
bool isPrime(T n)
{
    T i;
    if (n < 2) return false;
    else if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (i = 3; i <= n / i; i += 2)
        if (n % i == 0) return false;
    return true;
}

template<typename TYPE,std::size_t SIZE>
std::size_t array_length(const TYPE(&array)[SIZE])
{
    return SIZE;
}
class Solver
{
public:
    Solver(istream& i, ostream& o) :cin(i), cout(o){}
    int solve()
    {
        INPUT(int, A);
        INPUT(int, B);
        INPUT(int, C);
        INPUT(int, X);
        INPUT(int, Y);
        int result = 0;
        int rem = abs(X - Y);
        if(A + B > C * 2)
        {
            if(X > Y)
            {
                result += Y * C * 2;
                if(A > C * 2)
                {
                    result += rem * C * 2;
                }
                else
                {
                    result += rem * A;
                }
            }
            else
            {
                result += X * C * 2;
                if(B > C * 2)
                {
                    result += rem * C * 2;
                }
                else
                {
                    result += rem * B;
                }
            }
        }
        else
        {
            result = A * X + B * Y;
            
        }

        cout << result << endl;
        return 0;
    }
private:
    istream& cin;
    ostream& cout;
    
};
#ifndef TEST
int main(int argv, char* argc[])
{
    Solver s(cin, cout);
    return s.solve();
}
#else
class TestCase
{
public:
    string input;
    string expect;
    TestCase(string in, string expc) :input(in), expect(expc){}
};
vector<TestCase> inputs;
#define ADDTEST(i,o) inputs.push_back(TestCase(i,o));
void createTestCase()
{
    ADDTEST(
            "1500 2000 1600 3 2\n"
            ,
            "7900\n"
            );
    
}
int main(int argv, char* argc[])
{
    createTestCase();
    for (size_t i = 0; i < inputs.size(); ++i)
    {
        cout << "Case " << i + 1 << " is ";
        istringstream iss(inputs[i].input);
        ostringstream oss;
        Solver s(iss, oss);
        s.solve();
        string actual = oss.str();
        if (actual == inputs[i].expect)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "NG" << endl;
            cout << "\texpected :" << inputs[i].expect << endl;
            cout << "\tactual   :" << actual << endl;
        }
    }
    return 0;
}
#endif
