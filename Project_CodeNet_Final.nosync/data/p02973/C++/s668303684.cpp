#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int p[100010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int A[100010];
    rep(i, n) cin >> A[i];
    int cnt = 0;
    rep(i, 100010) p[i] = -1;
    rep(i, n) {
        int ok = cnt;
        int ng = -1;
        while(abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if(p[mid] < A[i]) ok = mid;
            else ng = mid;
        }
        p[ok] = A[i];
        cnt = max(cnt, ok + 1);

    }
    cout << cnt << endl;

    return 0;
}
