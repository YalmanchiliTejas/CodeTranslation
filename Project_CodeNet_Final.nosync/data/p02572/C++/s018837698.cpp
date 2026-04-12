#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n;
    cin >> n;
    vector <long long> A(n);
    rep(i,n) cin >> A[i];

    long long cur = A[n-2]; 
    long long sum = A[n-1];
    long long ans = 0;
    long long mod = 1000000007;
    
    for(int i=n-2; i>=0; i--){
        ans += (sum * A[i]) % mod;
        sum += A[i];
        sum %= mod;
    }

    cout << ans % mod << endl;
}