#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

// デバッグ用
#define _DEBUG
#ifdef _DEBUG
#define dlog(str) cout << "====" << str << endl;
#else
#define dlog(str)
#endif
// ここまで
#define INF 999999999
#define REP(i, n) for(int i = 0, i##_l = (n); i < i##_l; i++)
#define REPR(i, n) for(int i = n - 1; 0 <= i; i--)
#define FOR(i, s, e) for(int i = s; i <= e; i++)
#define FORR(i, s, e) for(int i = s; e <= i; i--)
#define LLI long long int
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define bit(a, shift) ((a>>shift)&1))
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))

int main() {
    int N;
    cin >> N;
    int ma = 0, cu, c = 0;
    REP(i, N) {
        cin >> cu;
        if(ma <= cu) {
            c++;
            chmax(ma, cu);
        }
    }
    cout << c;
    return 0;
}