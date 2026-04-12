#include<bits/stdc++.h>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    long long int n;
    cin >> n;
    
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    /*
    long long int s[n];
    s[0] = a[0];
    for(int i=1;i<n;i++){
        s[i] *= (s[i-1]%1000000007);  
    }
    
    long long int sum=0;
    for(long long int i=0;i<=n-2;i++){
        for(long long int j=i+1;j<=n-1;j++){
            sum += ((a[i]*a[j])%1000000007);
            sum %= 1000000007;
        }
    }
    cout << sum << endl;
    */

   /*----------------------------------------------
    解説：累積和を用いて処理しよう！
    a[i]*a[i+1] + a[i]*a[i+2] + ... + a[i]*a[n]
    = a[i] * (a[i+1] + a[i+2] + ... + a[n])
    この()内で累積和を用いる
   ----------------------------------------------*/
   long long int sum[n]; //累積和 sum[0] = a[0], sum[1] = sum[0] + a[1], sum[2] = sum[1] + a[2], a[i]+...+a[j]=s[j]-s[i-1]
   sum[0] = a[0];
   for(int i=1;i<n;i++){
       sum[i] = sum[i-1] + a[i];
       sum[i] %= 1000000007;
   }

   long long int ans = 0;
    long long int mod_sum;
   for(int i=0;i<n;i++){
       //cout << i << " " << sum[n-1] - sum[i] << endl;
       mod_sum = (sum[n-1]-sum[i]) % 1000000007;
       if(mod_sum<0){
           mod_sum+=1000000007;
       }
       ans += (a[i]*mod_sum % 1000000007);
       ans %= 1000000007;
   }
   ans %= 1000000007;
    cout << ans << endl;
}