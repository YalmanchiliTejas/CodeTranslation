#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e15
typedef long long ll;

int N;
int N_MAX = 1e5;
vector<int> A(N_MAX, INF);
vector<ll> dp(N_MAX, INF);
//multiset<int> dp;

int main() {
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }
    dp[0] = A[N-1];//広義単調減少列の最長の長さでは？
    FOR(i,1,N){
        auto itr = upper_bound(ALL(dp), A[N-1-i]);
        *itr = A[N-1-i];
    }

    auto len = lower_bound(ALL(dp), INF);
    int ans = len - dp.begin();
    cout << ans << endl;

    // dp.insert(A[0]);
    // FOR(i,1,N){
    //     auto itr = lower_bound(ALL(dp), A[i]);
    //     if(itr != dp.begin()){//更新できるときは貪欲に最大のものを選ぶ
    //         itr--;
    //         dp.erase(itr);
    //     }
    //     dp.insert(A[i]);
    // }

    // cout << dp.size() << endl;


    return 0;
}