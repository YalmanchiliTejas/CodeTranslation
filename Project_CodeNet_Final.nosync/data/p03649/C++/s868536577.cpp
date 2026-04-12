#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}

long long arr[51], cur[51];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    long long diff, tot = 0;

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    for(int i = 0; i < 1250; ++i){
        for(int j = 0; j < n; ++j){
            diff = (arr[j] + (tot - cur[j])) - (n - 1);
            diff = diff / n + (diff % n > 0);
            tot += diff;
            cur[j] += diff;
            arr[j] -= n * diff;
        }
    }

    cout << tot << "\n";

    return 0;

}
