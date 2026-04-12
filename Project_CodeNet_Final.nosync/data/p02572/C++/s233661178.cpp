#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;

ll N;
ll A[210000];
ll MOD = 1000000007;


int main(void){

    ll sum = 0;

    cin >> N;
    for (int i = 1; i <= N;i++) {
        cin >> A[i];
        sum = (sum + A[i]) % MOD;
    }

    ll ans = 0;

    for (int i = 1; i < N;i++){
        if (A[i] > sum) sum = MOD + sum - A[i];
        else sum = sum - A[i];

        ans = (ans + sum * A[i]) % MOD;

    }

    cout << ans << endl;
    
    return 0;
}
