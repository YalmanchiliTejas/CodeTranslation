#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    ll N;
    cin >> N;
    vector<pll> X(N), Y(N);
    REP(i, N){
        cin >> X[i].first;
        X[i].second = i;
    }
    sort(X.begin(), X.end());
    REP(i, N){
        Y[i].first = X[i].second;
        Y[i].second = i;
    }
    sort(Y.begin(), Y.end());
    REP(i, N){
        ll res;
        Y[i].second < N/2 ? res = X[N/2].first : res = X[N/2-1].first;
        cout << res << endl;
    }
    return 0;
}