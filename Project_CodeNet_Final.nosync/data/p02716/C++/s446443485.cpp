#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <numeric>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    ll N;
    cin >> N;
    ll N1 = N / 2;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    /*
    if (N % 2 == 0){
        ll a = 0, b = 0;
        REP(i, N){
            if (i % 2 == 0) a += A[i];
            else b += A[i];
        }
        cout << max(a, b) << endl;
        return 0;
    }
    */
    A.push_back(-1e18);
    A.push_back(-1e18);
    vector<vector<ll>> v(N+5, vector<ll>(3, -1e18));
    v[0][0] = 0;
    //v[0][1] = 0;
    REP(i, N+2)REP(j, 3){
        v[i+2][j] = max(v[i+2][j], v[i][j] + A[i]);
        if (j != 2) v[i+1][j+1] = max(v[i+1][j+1], v[i][j]);
    }

    cout << max(v[N+1][2], v[N+1][1]) << endl;
    return 0;
}

