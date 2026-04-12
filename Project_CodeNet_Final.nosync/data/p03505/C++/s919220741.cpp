#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll K,A,B; cin >> K >> A >> B;
    if(A <= B){
        if(K <= A){
            cout << 1 << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }
    ll res = LLONG_MAX;
    for(int i = -1; i <= 1;i++){
        ll cost = B*i;
        ll tmp = (K + cost)/(A-B);
        if((K+cost)%(A-B) != 0) tmp++;
        res = min(res,tmp*2 + i);
    }
    cout << res << endl;
    return 0;
}
