#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;
//a % b >= K
// bを固定
int main(){
    ll N,K;
    cin >> N >> K;
    if(K == 0){
        cout << N*N << endl;
        return 0;
    }
    ll res = 0;
    for(int i = 1; i <= N; i++){
        if(i - 1 >= K ) {
            res += N/i*(i-K);
            res += max(0LL,(N%i) - K + 1);
        }
    }
    cout << res << endl;
    return 0;
}