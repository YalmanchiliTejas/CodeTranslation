#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <cmath>
#include <sstream>
#include <random>
#include <ctime>
#include <chrono>
#include <iomanip>
 
#define fi first
#define se second
#define LL(x) (x << 1)
#define RR(x) ((x << 1) + 1)
#define mp make_pair
 
using namespace std;
const int N = 3005;
const int M = 30000;
 
const int Bases = 2;
const long long base[] = {137, 37};
const long long mod = 1000000007LL;
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> iiii;

long long addi(long long a, long long b, long long m = mod) { a += b; if (a < 0) a += m; if (a >= m) a -= m; return a; }
long long subt(long long a, long long b, long long m = mod) { a -= b; if (a < 0) a += m; if (a >= m) a -= m; return a; }
long long mult(long long a, long long b, long long m = mod) { return a * b % m; }
long long power(long long a, long long b, long long m = mod) 
{
    long long tmp = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1LL) tmp = mult(tmp, a, m);
        a = mult(a, a, m);
    }
    return tmp;
}
long long inv(long long a, long long m = mod) { return power(a, m - 2, m); }
unsigned replaceByte(unsigned x, int i, char b)
{
    x = x & ~(0xff << (i * 4));
    // return x;
    unsigned y = 0xff & (unsigned)b;
    // return y;
    x = x | (y << (i * 4));
    return x;
}

/* ------------------------------------------ template end here ------------------------------------------ */

long long n, a[N], F[N][N];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) F[i][i] = a[i];
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 1; i <= n - len + 1; ++i)
        {
            int j = i + len -1;
            F[i][j] = max(a[i] - F[i + 1][j], a[j] - F[i][j - 1]);
        }
    }
    cout << F[1][n];
    return 0;
}
/*
1
acbba
*/