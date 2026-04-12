#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long MOD = 1000000007;
    long long N; 
    cin >> N;
    long long A;

    long long ans = 0;
    long long souwa = 0;
    for(int i = 0; i < N; i++){
        cin >> A;
        ans += souwa * A % MOD;
        souwa += A % MOD;

        if(souwa > MOD){
            souwa = souwa % MOD;
        }
        
        if(ans > MOD){
            ans = ans % MOD;
        }

    }

    cout << ans << endl;
}