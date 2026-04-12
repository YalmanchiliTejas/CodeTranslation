#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <iomanip>
#include <math.h>
#include <map>
#include <algorithm>
#define M_PI 3.14159265358979323846264338327950288
#define oo 998244353
#define maxN 200007
using namespace std;

map <long long, int> check;
long long f[maxN];

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    long long n, x, m;
    cin >> n >> x >> m;
    long long res = x;
    int trace = 0;
    f[1] = res;
    check[res] = 1;
    int pos = 0;
    for (int i = 2; i <= m+10; ++i) {
        res = (res*res)%m;
        f[i] = f[i-1]+res;
        if (check[res] != 0) {
            trace = i;
            pos = check[res];
            break;
        }
        check[res] = i;
    }

    if (n <= trace) cout << f[n] << endl;
    else {
        n -= pos;
        int dist = trace-pos;
        long long a = f[pos+n%dist];
        long long b = (f[trace]-f[pos])*(n/dist);
        cout << a+b << endl;
    }
    return 0;
}