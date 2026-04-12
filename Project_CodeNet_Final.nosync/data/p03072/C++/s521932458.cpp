// SeeAlso: https://atcoder.jp/contests/abc124/tasks/abc124_b

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

#define MAX 4

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

using namespace std;

int main() {
    int N;
    int H[100];

    cin >> N;

    REP(i, N) {
        cin >> H[i];
    }

    int ans = 0;
    int height = 0;

    REP(i, N) {
        if (height <= H[i]) {
            ans++;
        }

        CHMAX(height, H[i]);
    }

    cout << ans << endl;
    return 0;
}
