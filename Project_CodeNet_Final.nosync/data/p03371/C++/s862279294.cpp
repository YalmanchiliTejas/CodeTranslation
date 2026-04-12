#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int INF = 1001001001;
const ll LINF = 1e18;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    T r;
    while((r=a%b)) {
        a = b; b = r;
    }
    return b;
}

ll A, B, C, X, Y;

int main(){
    cin >> A >> B >> C >> X >> Y;
    
    ll cost = LINF;
    for (ll i = 0; i <= 2 * max(X, Y); i++) {
        if(i % 2 != 0) continue;
        ll leftA = max(X - i / 2, (ll)0);
        ll leftB = max(Y - i / 2, (ll)0);
        ll tmp = leftA * A + leftB * B + i * C;
        cost = min(cost, tmp);
    }
    
    cout << cost << endl;
    
    return 0;
}
