    #include<bits/stdc++.h>
    using namespace std;
    int main(){
      int mod=1000000007;
      int n;
      long long int sum=0;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
        cin>>arr[i];
      long long int tsum=0;
      for(int i=0;i<n;i++)
       tsum=(tsum+arr[i])%mod;
      for(int i=0;i<n;i++){
        tsum-=arr[i];
        if(tsum<0)
          tsum+=mod;
        int prod=(arr[i]*tsum)%mod;
        sum=(sum+prod)%mod;
      }
      cout<<sum;
      return 0;
    }