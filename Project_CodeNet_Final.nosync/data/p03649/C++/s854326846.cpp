#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    ll N; cin >> N;
    ll A[N]; rep(i, N) cin >> A[i];
    ll K[N] = {};
    ll acc = 0;
    ll ans = 0;
    while(true){
        acc = 0;
        rep(i, N){
            if(A[i] <= N-1) K[i] = 0;
            else{
                K[i] = (A[i]+1-N)/N;
                if((A[i]+1-N) % N) K[i]++;
                acc += K[i];
            }
        }
        if(acc == 0) break;
        rep(i, N){
            A[i] += (acc-K[i])-K[i]*N;
        }
        ans += acc;
    }
    cout << ans << endl;
    return 0;
}