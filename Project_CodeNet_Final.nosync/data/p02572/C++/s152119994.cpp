#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
 
int main(){
    int N;
    cin >> N;
    ll A[N];
    for(int i=0;i<N;i++)
        cin >> A[i];

    ll ans = 0, sum;
    for(int i=N-2;i>=0;i--){
        sum += A[i+1];
        sum = sum % MOD;
        ans += A[i]*sum;
        ans = ans % MOD;
    }

    cout << ans << endl;

}