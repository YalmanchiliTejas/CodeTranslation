#include <bits/stdc++.h> 
#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using vp = vector<P>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvb = vector<vb>;
const int INF = 1e9;
const int MOD = 1e9+7;


signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    string S; cin >> S;
    if(S == "AAA" || S == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
}