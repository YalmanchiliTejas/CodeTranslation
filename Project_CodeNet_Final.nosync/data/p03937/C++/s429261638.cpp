#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, k, n) for(auto i = k; i != n; i++)
#define rrep(i, n) RREP(i, n, 0)
#define RREP(i, n, k) for(auto i = n; i != k; i--)
#define all(x, r) (x), (x)+(r)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " " << x << endl
#define exst(x, data) (data).find(x) != (data).end()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define np next_permutation
#define b32 bitset<32>

using ll = long long;
using Pii = pair<int,int>;
using Tiii = tuple<int, int, int>;
template<class T>using V = vector<T>;

const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    char A[10][10]; memset(A, '.', sizeof(A));
    int H, W; cin >> H >> W;
    REP(i,1,H+1) REP(j,1,W+1) cin >> A[i][j];

    REP(i,1,H+1) REP(j,1,W+1) {
        if(A[i][j] == '.') continue;
        int cnt = 0; rep(k,4) if(A[i +dy[k]][j +dx[k]] == '#') cnt++;

        if((i==1 && j==1) || (i==H && j==W)) {
            if(cnt!=1) {
                cout << "Impossible" << endl;
                return 0;
            }
        } else {
            if(cnt!=2) {
                cout << "Impossible" << endl;
                return 0;
            }
        }

        if(A[i-1][j]=='#' && A[i][j-1]=='#') {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    return 0;
}
