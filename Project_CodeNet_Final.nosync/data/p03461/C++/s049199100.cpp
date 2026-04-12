#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int N = 110;
int d[12][12], c[N][N], ma[12][12];

int main() {
    int a, b;
    cin >> a >> b;
    FOR(i,1,a) FOR(j,1,b){
        cin >> d[i][j];
        ma[i][j] = 1e9;
    }

    REP(cx,N) REP(cy,N) FOR(i,1,a) FOR(j,1,b){
        c[cx][cy] = max(c[cx][cy], d[i][j] - cx * i - cy * j);
    }

    REP(cx,N) REP(cy,N) FOR(i,1,a) FOR(j,1,b){
        ma[i][j] = min(ma[i][j], cx * i + cy * j + c[cx][cy]);
    }

    FOR(i,1,a) FOR(j,1,b){
        if (ma[i][j] != d[i][j]){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    int m = 2 * (N-1) + N * N;

    cout << "Possible" << endl;
    cout << 300 << " " << m << endl;
    REP(i,N-1) cout << i+1 << " " << i+2 << " X" << endl;
    REP(i,N-1) cout << 299-i << " " << 300-i << " Y" << endl;
    REP(i,N) REP(j,N) cout << i+1 << " " << 300-j << " " << c[i][j] << endl;
    cout << "1 300" << endl;
    
    return 0;
}