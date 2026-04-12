#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    int h, w; cin >> h >> w;
    string a[10];
    REP(i, h) {
        cin >> a[i];
    }
    REP(i, h) {
        REP(j, w) {
            if (((i == h - 1) && (j == w - 1))) {
                // 最初のマス、最後のマスについては二方向に '#' がある場合はNG
                if ((a[i-1][j] == '#') && (a[i][j-1] == '#')) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            } else if ((a[i][j] == '#') && (a[i+1][j] != '#') && (a[i][j+1] != '#')) {
                // 終点以外のすべての通過マスについて、右も下も '.' だとNG
                cout << "Impossible" << endl;
                return 0;
            } else {
                // 三方向に '#' がある場合はNG
                int c = 0;
                if ((0 < i) && (a[i-1][j] == '#')) {
                    c++;
                }
                if ((i < h - 1) && (a[i+1][j] == '#')) {
                    c++;
                }
                if ((0 < j) && (a[i][j-1] == '#')) {
                    c++;
                }
                if ((j < w - 1) && (a[i][j+1] == '#')) {
                    c++;
                }
                if (c > 2) {
                    cout << "Impossible" << endl;
                    return 0;
                }

                // 最初のマス、最後のマスについては二方向に '#' がある場合はNG
                if ((i == 0) && (j == 0) && (a[i+1][j] == '#') && (a[i][j+1] == '#')) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                if ((i == h-1) && (j == w-1) && (a[i-1][j] == '#') && (a[i][j-1] == '#')) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}