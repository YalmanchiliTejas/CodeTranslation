#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i<n; i++)
#define ALL(a) begin(a), end(a)

int main (void) {
    int H,W;
    cin>>H>>W;
    vector<string> A;
    REP(i,H) {
        string temp;
        cin>>temp;
        bool white = true;
        REP(j,W) {
            if (temp[j] == '#') white = false;
        }
        if (!white) A.pb(temp);
    }
    int HH = A.size();
    vector<string> ans(HH);
    REP(i,W) {
        bool white = true;
        REP(j,HH) if (A[j][i] == '#') white = false;
        if (white) continue;
        REP(j,HH) {
            ans[j].pb(A[j][i]);
        }
    }
    REP(i,HH) cout<<ans[i]<<endl;
    return 0;
}