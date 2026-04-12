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

int cnt[26][51] = {};
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string S[51];
    rep(i, n) cin >> S[i];
    rep(i, n) {
        rep(j, S[i].length()) {
            cnt[S[i][j] - 'a'][i]++;
        }
    }
    rep(i, 26) {
        int len = INF;
        rep(j, n) len = min(len, cnt[i][j]);
        rep(j, len) cout << (char)('a' + i);
    }
    cout << endl;

    return 0;
}
