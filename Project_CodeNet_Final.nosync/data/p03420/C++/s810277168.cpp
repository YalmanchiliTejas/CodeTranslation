#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K; cin >> N >> K;
    ll cnt = 0;
    if(K == 0){
        cout << N*N << endl;
        return 0;
    }
    for(ll i = K+1; i <= N; i++){
        ll tmp=N%i-(K-1);
        if(tmp<0)tmp=0;
        if(N%i==0)tmp=0;
        cnt+= (N/i)*(i-K)+tmp;
        //cout << (N/i)*(i-K)+tmp << endl;
    }
    cout << cnt << endl;
}