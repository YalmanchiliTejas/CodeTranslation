#include<bits/stdc++.h>
#include <math.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
     long long int a[200001];

     long long int res = 0;

    long n;
    cin >> n;
     long long int all = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        all = (all + a[i]) % mod;
    }
     long long int current_sum = all;
    for(int i = 0; i < n; i++) {
         long long int val = 0;
        current_sum = (current_sum - a[i])%mod;
        if(current_sum < 0) {
            current_sum += mod;
        }
        //cout << current_sum << endl;
        val = (current_sum * a[i]) % mod;
        res = (res + val) % mod;
    }
    res = (res) % (mod);
    cout << res << endl;
}