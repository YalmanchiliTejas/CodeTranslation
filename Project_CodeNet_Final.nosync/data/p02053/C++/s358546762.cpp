#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];
    vector<int> B(H + W - 1), C(H + W - 1);
    rep(i, H) rep(j, W) {
        if(A[i][j] == 'B') {
            B[i + j] = 1;
            C[H - 1 - i + j] = 1;
        }
    }
    int minB = inf, maxB = 0;
    int minC = inf, maxC = 0;
    rep(i, H + W - 1) {
        if(B[i] == 1){
            minB = min(minB, i);
            maxB = max(maxB, i);
        }
        if(C[i] == 1) {
            minC = min(minC, i);
            maxC = max(maxC, i);
        }
    }
    
    output(max(maxB - minB, maxC - minC));
    
    
    
    return 0;
}

