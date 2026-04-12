/* Copyright 2016 AcrossTheSky */
#include <iostream>
#include <cstdio>
#include <utility>
#include <cassert>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define RVC(i, c) fot (int i = 0; i < (c).size(); ++i)
#define RED(k, u) for (int k = head[(u)]; k; k = edge[k].next)
#define SQR(k) (k) * (k)
#define lowbit(x) ((x) & (-(x)))
#define CL(x, v) memset(x, v, sizeof x)
#define MP std::make_pair
#define PB push_back
#define FR first
#define SC second
#define rank rankk
#define next nextt
#define link linkk
#define index indexx
#define abs(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
typedef long long LL; typedef pair<int, int> PII;

template<class T> inline
bool getmin(T *a, const T &b) {
    if (b < *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
bool getmax(T *a, const T &b) {
    if (b > *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
void read(T *a) {
    char c;
    while (isspace(c = getchar())) {}
    bool flag = 0;
    if (c == '-') flag = 1, *a = 0;
    else
        *a = c - 48;
    while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
    if (flag) *a = -*a;
}

const int mo = 1000000007;
template<class T>
T pow(T a, T b, int c = mo) {
    T res = 1;
    for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c) if (b & i) res = 1LL * res * a % c;
    return res;
}
/*======================= TEMPLATE =======================*/
bool cmp(const PII &A, const PII &B) {
    return A.FR + A.SC == B.FR + B.SC;
}

PII a[100];
int n, m;

int main() {
    cin >> n >> m;
    int k = 0;
    REP(i, 1, n) REP(j, 1, m) {
        char c;
        while (isspace(c = getchar()));
        if (c == '#') a[++k] = MP(i, j);
    }
    if (k != n + m - 1) 
        return cout << "Impossible" << endl, 0;
    sort(a + 1, a + k + 1);
    REP(i, 2, k) {
        if (a[i].FR == a[i - 1].FR) {
            if (a[i].SC != a[i - 1].SC + 1) 
                return cout << "Impossible" << endl, 0;
        } else if (a[i].SC == a[i - 1].SC) {
            if (a[i].FR != a[i - 1].FR + 1) 
                return cout << "Impossible" << endl, 0;
        } else 
                return cout << "Impossible" << endl, 0;
    }
    return cout << "Possible" << endl, 0;
}
