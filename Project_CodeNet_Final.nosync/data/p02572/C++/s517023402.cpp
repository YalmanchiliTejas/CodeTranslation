#include <iostream>

using namespace std;
long long MOD = 1e9+7;
int main()
{
     long long n,sum=0;
    cin>>n;
    long long Arr[n];
    long long pSa[n];
    for(long long i=0 ; i < n ; i++){
        
        cin>>Arr[i];
    }
    for (long long j=0 ;j<n;j++){
        if(j==0){
            pSa[0]=Arr[0];
        }
      else{
          pSa[j]=pSa[j-1]+Arr[j];
      }
    }
    for(long long k=0;k<n;k++){
        long long a = Arr[k]%MOD;
        long long b = (pSa[n-1] - pSa[k])%MOD;
        long long c = ((a%MOD)*(b%MOD))%MOD;
        sum += c%MOD;
    }
    cout<<sum%MOD<<endl;
   return 0;
}