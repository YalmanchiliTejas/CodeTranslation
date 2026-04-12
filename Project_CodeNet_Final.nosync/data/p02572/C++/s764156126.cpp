#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DIV = 1e9+7;

int main() {
    
    long N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> sum(N);
    for(size_t i=0;i<N; i++)
        cin >> A[i];
    
    for(ll i=N-2;i>=0;i--)
        sum[i] = (sum[i+1] + A[i+1]) % DIV;
        

    ll total = 0;
    for(size_t i=0;i<N-1; i++)  {
        total += (A[i] * sum[i]) %DIV;
        total %= DIV;
    }
    cout << total << endl;

    return 0;
}
