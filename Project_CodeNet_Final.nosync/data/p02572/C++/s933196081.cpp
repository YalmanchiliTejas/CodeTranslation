#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
int mod(long long x){return (x % MOD + MOD ) % MOD;}
int main(){
    long long sum = 0 , ans = 0;
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0 ; i < N ; i++)
        cin >> arr[i] , sum += arr[i];

    for (int i = 0 ; i < N - 1 ; i++){
        sum = mod(sum - arr[i]);
        ans = (ans + sum * arr[i] % MOD) % MOD;
    }
    cout << ans << endl;
}
