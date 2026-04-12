#include<bits/stdc++.h> 
#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
const int INF = 1e9;
const int MOD = 1e9+7;


signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    vi A(N);
    REP(i, N)
    {
        int t; cin >> t;
        A[i] = -t;
    }
    vi S; 
    REP(i, N)
    {
        auto itr = upper_bound(ALL(S), A[i]);
        if(itr == S.end()) S.push_back(A[i]);
        else *itr = A[i];
    }
    cout << S.size() << endl;
}