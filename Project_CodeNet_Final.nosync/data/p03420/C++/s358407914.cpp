#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,K;
    cin >> N >>K;
    if(K==0){
        cout << N*N <<endl;
        return 0;
    }
    ll ans =0;
    for(ll b=K+1;b<=N;b++){
        ans += (N/b)*(b-K);
        ans += max(0LL,(N%b)-(K-1));
    }
    cout << ans << endl;
    return 0;
}