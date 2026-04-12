#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long mod = 1e9 + 7;

int n;
long long arr[N];
long long power(long long x, long long y, long long p){
    long long res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
void solve(){
    long long sum = 0, sum1 = 0;
    int i = 0;
    for(i = 0; i < n; i++){
        sum += arr[i];
        sum %= mod;
        sum1 += (arr[i] * arr[i]) % mod;
        sum1 %= mod;
    }
    sum *= sum;
    sum %= mod;
    sum -= sum1;
    sum += mod;
    sum %= mod;
    sum *= power(2, mod - 2, mod);
    sum %= mod;
    cout << sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int i = 0;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    solve();
    return 0;
}