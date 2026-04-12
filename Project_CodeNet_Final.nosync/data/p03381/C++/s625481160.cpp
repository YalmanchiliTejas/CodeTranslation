#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define int long long
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> X(N);
    REP(i, N) cin >> X[i];
    vector<int> A(X);
    sort(All(A));

    REP(i, N){
        if(lower_bound(All(A), X[i])-A.begin() < N/2) cout << (A[N/2]) << "\n";
        else cout << (A[N/2 - 1]) << "\n";
    }
    return 0;
}