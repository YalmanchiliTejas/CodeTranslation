#include<bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long long int ans=0;
    long long int sum=0;
    for(int i=n-1;i>0;i--){
        sum += a[i];
        sum %= MOD;
        ans+=a[i-1]*sum%MOD;
        ans%=MOD;
    }

    cout << ans << endl;
    
    return 0;
}
