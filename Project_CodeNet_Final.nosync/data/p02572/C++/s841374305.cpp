#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int main(void){
    int N;
    ll num, sum, ans, MOD;
    vector<ll> A;
    sum = 0;
    ans = 0;
    MOD = 1e9+7;
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> num;
        sum += num;
        A.push_back(num);
    }
    
    for (int i = 0; i < N - 1; i++){
        ll temp;
        sum -= A[i];
        temp = sum % MOD;
        ans += A[i] * temp;
        ans %= MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}