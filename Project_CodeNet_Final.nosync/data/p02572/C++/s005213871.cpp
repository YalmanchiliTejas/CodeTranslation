#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(void){
   int64_t n;
   int64_t sum = 0;
   cin >> n;
   int64_t a[n], acc[n+1];
   for(int i=0; i<n+1; i++)
   {
        acc[i] = 0;
   }
   for(int i=0; i<n; i++)
   {
        cin >> a[i];
        a[i] %= mod;
        acc[i+1] += acc[i] + a[i];
   }
   
   for(int i=0; i<n; i++)
   {
        sum += a[i] * ((acc[n]-acc[i+1]) % mod);
        sum %= mod;
   }
   
   cout << sum << endl;
}
