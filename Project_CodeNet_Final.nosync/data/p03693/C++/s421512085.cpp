#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if((10*g + b)%4) {
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}

