//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    
    long long int i,j,n,res = 0;
    cin >> n;
    long long int a[n];
    long long int suff[n];
    for(i = 0;i<n;i++) cin >> a[i];
    for(i = n-1;i>=0;i--){
        if(i == n-1) suff[i] = a[i];
        else suff[i] = suff[i+1] + a[i];
    }
    for(i = 0;i<n-1;i++) res = ((res % MOD) + (((a[i] % MOD) * (suff[i+1] % MOD)) % MOD)) % MOD;
    cout << res << endl;
    return 0;
}