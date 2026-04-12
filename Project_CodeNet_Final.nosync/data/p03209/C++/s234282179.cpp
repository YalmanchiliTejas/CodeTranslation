#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N,K,i;
    cin >> N >> K;
  
    ll A[N + 1];
    ll P[N + 1];
    A[0] = 1;
    P[0] = 1;
    for(i = 1;i <= N;i++){
        A[i] = 2 * A[i - 1] + 3;
        P[i] = 2 * P[i - 1] + 1;
    }
    ll count = 0;
    for(i = N; i > 0; i--){
        if(K == 0) break;
        K--;
        if(K <= A[i - 1]) continue;
        K -=A[i - 1] + 1;
        count += P[i - 1] + 1;
    }
    if(K) count++;
    cout << count << "\n";
    return 0;
}