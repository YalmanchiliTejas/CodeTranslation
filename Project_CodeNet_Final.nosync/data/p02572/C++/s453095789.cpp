#include<iostream>
using namespace std;

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    long long a[n],sum = 0,ans = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0;i < n;i++){
        sum -= a[i];
        long long x = (a[i]%mod)*(sum%mod)%mod;
        ans = (ans + x)%mod;
    }

    cout << ans%mod << endl;
    return 0;
}
