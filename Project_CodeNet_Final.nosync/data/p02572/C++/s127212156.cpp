#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
ll cnt =0,ans=0;

int main(){
   int n;   cin >> n;
   ll a[n+1],b[n+1];
   b[0] = 0;
   for(int i=1;i<=n;i++){
       cin >> a[i];
       b[i] =(b[i-1]+a[i])%MOD;
    }

    for(int i=1;i<=n;i++){
        if(b[n]-b[i]<0) b[n]+=MOD;
        ans += a[i]*(b[n]-b[i]);
        ans = ans % MOD;
    }
    
    

    cout << ans%MOD << endl;
}