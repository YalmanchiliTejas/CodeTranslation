// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int power(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) 
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int findProductSum(int A[], int n) 
{ 
    // calculating array sum (a1 + a2  ... + an) 
    int array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = array_sum + A[i]; 
    array_sum %= mod;
    // calcualting square of array sum 
    // (a1 + a2 + ... + an)^2 
    int array_sum_square = array_sum * array_sum % mod; 
  
    // calcualting a1^2 + a2^2 + ... + an^2 
    int individual_square_sum = 0; 
    for (int i = 0; i < n; i++) {
        individual_square_sum += A[i]*A[i];
        individual_square_sum %= mod; 
    }
  
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
    return (array_sum_square - individual_square_sum + mod) * power(2, mod - 2) % mod; 
} 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i =0 ; i < n; i++)
            cin >> a[i];

        int ans = findProductSum(a, n) % mod;
        cout << ans << '\n';
    }
    
    return 0;
}

