#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    llint N, K;
    cin >> N >> K;
    llint ans = 0;
    if(K == 0) ans = N*N;
    else{
        FOR(b, K+1, N+1){
            ans += (llint)N/b*(b-K);
            ans += max((llint)0, N%b-K+1);
        }
    }
    cout << ans << "\n";
    return 0;
}