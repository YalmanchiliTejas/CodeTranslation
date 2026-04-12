#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,K;
    cin >> N >> K;
    if(K==0){
        cout << N*N << endl;
        return 0;
    }
    ll cnt = 0;
    for(ll b=1;b<=N;b++){
        // aをbで割った余りは1,2,..,b-1,0,1,2,...b-1,0,1...
        // 1,2,...b-1,0 を一塊とすると、k以上の数は(b-1)-k+1 = b-k個
        // 塊はN/b個ある
        // 端数はN%bあるのでその中でk以上の数はN%b-k+1個
        cnt += max(b-K,0LL)*(N/b) + max(0LL,N%b-K+1);
    }
    cout << cnt << endl;
    return 0;
}