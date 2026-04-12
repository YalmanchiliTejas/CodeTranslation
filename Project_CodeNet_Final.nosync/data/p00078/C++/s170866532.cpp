#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <ctime>
using namespace std;

#define rep(i,a,n) for(int i=a; i<n; i++)
#define repr(i,a,n) for(int i=a; i>=n; i--)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 999999999

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long int ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int const MOD = 1000000007;

namespace std {
    bool operator<(const P a, const P b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

int ans[15][15];
int n;
int i, j;

void solve(int x, int y, int k) {
    if(0 <= x && x < n && 0 <= y && y < n) {
        if(ans[x][y] == -1) {ans[x][y] = k; i = x; j = y; return;}
        else solve(x+1,y-1,k);
    }
    else if(x >= n) solve(0,y,k);
    else if(y >= n) solve(x,0,k);
    else if(y < 0) solve(x,n-1,k);
}

int main() {
    while(cin >> n) {
        memset(ans, -1, sizeof(ans));
        int mid = n / 2;
        i = mid + 1; j = mid;
        ans[i][j] = 1;

        rep(k,2,n * n + 1) solve(i+1, j+1, k);

        rep(i,0,n) {
            rep(j,0,n) {
                printf("%4d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}