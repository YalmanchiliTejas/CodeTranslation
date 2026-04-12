#include "bits/stdc++.h"
using namespace std;
#define OUT(x)                cout << #x << " = " << x << endl
#define rep(i, n)             for (int (i) = 0; (i) < (int)(n); (i)++)
#define rer(i, l, r)          for (int (i) = (int)(l); (i) <= (int)(r); (i)++)
#define reu(i, l, r)          for (int (i) = (int)(l); (i) < (int)(r); (i)++)
#define all(x)                (x).begin(), (x).end()
#define rall(x)               (x).rbegin(), (x).rend()
template<typename T> void pv(T a, T b) { for (T i = a; i != b; i ++) cout << *i << " "; cout << endl; }
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
int in() { int x; scanf("%d", &x); return x; }
long long lin() { long long x; scanf("%lld", &x); return x; }

signed main() { 
        int a, b, c;
        cin >> a >> b >> c;
        cout << ((b * 10  + c) % 4 == 0 ? "YES" : "NO") << endl;
        return 0;
}               

