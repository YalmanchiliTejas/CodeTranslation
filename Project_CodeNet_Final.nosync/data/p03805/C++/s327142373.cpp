#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(2e5 + 5);
const double EPS = 1e-8;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int main() {
    int n, m, g[10][10]{}, ans=0;
    cin >> n >> m;
    REP(i,m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    vector<int> ls;
    REP(i,n-1) ls.push_back(i+1);
    while(1){
        bool ok = true;
        REP(i,n-1){
            ok &= g[ls[i]][ls[i+1]];
        }
        if(ok) ans++;
        if(!next_permutation(ALL(ls)))break;
    }
    cout << ans << endl;
    return 0;
}
