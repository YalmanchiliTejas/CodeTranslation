#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <valarray>
#include <utility>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,n) for(int i=1;i<=(int)(n);i++)
#define rep3(i,n) for(int i=0;i<=(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define REP2(i,m,n) for(int i=m+1;i<=(int)(n);i++)
#define REP3(i,m,n) for(int i=m;i<=(int)(n);i++)
#define INF 2000000000
#define INFLL 9000000000000000000
#define MOD 1000000007

typedef long long int ll;

int main() {
    // a 0x61 z 0x7a
    const int AZ = 0x7a - 0x61 + 1;

    int n;
    cin >> n;

    string s[n];

    rep(i, n) {
        cin >> s[i];
    }

    int alphabet[n][AZ] = {};

    rep(i, n) {

        rep(j, s[i].length()) {
            alphabet[i][(int) s[i][j] - 0x61]++;
        }
    }

    rep(j, AZ) {
        int Min = 50;

        rep(i, n) {
            Min = min(Min, alphabet[i][j]);
        }

        rep(i, Min) {
            cout << (char) (j + 0x61);
        }
    }

    cout << endl;
    return 0;
}
