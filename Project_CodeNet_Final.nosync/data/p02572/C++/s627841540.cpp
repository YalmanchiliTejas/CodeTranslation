#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    cin >> n;
    long long a[n];
    long long sum=0;
    long long result=0;
    long long num=0;
    long long mod=1000000007;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        sum-=a[i];
        num=((a[i]%mod)*(sum%mod))%mod;
        result = (result%mod + num%mod)%mod;
    }
    cout << (result) << endl;

    return 0;
}