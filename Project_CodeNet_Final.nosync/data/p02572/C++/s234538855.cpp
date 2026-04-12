#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N; 
    vector<ll> A(N);
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum = (sum + A[i]) % 1000000007;
        
    }
    ll ans = 0;
    for(int i = 0; i < N - 1; i++) {
        
        if(sum - A[i] < 0){ 
            ans = (ans + (A[i] % 1000000007) * ((sum + 1000000007 - A[i]) % 1000000007) % 1000000007) % 1000000007;
            sum = (sum + 1000000007 - A[i]) % 1000000007; }
        else {ans = (ans + (A[i] % 1000000007) * ((sum - A[i]) % 1000000007) % 1000000007) % 1000000007;
              sum = (sum - A[i]) % 1000000007;
        }
    }

    cout << ans % 1000000007;
    return 0;
}