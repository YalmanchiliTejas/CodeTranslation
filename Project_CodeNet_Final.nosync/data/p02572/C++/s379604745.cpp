#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;
int n;
long long arr[N];

long long binpow(long long a, long long b){
    if(b == 0){
        return 1;
    } else {
        long long x = binpow(a, b / 2);
        long long res = (x * x) % MOD;
        if(b & 1){
            res = (res * a) % MOD;
        }
        return res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long sum = 0;
    long long pows = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];

        sum = (sum + arr[i]) % MOD;
        long long k = (arr[i] * arr[i]) % MOD;
        pows = (pows + k) % MOD;
    }

    long long res = (sum * sum) % MOD;
    res = (res - pows) % MOD;
    if(res < 0){
        res += MOD;
        res = res % MOD;
    }


    res = (res * binpow(2, MOD - 2)) % MOD;

    cout << res << '\n';




    return 0;
}