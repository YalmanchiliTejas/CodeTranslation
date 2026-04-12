#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define f(i,s,n) for(int i=s;i<=n;++i)
const lli mx = 1e9+7;
int main(){
   lli n;
   cin>>n;
   vector<int> arr(n);

   f(i,0,n-1){
       cin>>arr[i];
   }
   vector<int> temp(n+1, 0);
    temp[n]=0;

    lli sum=0;
   for(int i=n-1;i>=0;--i){
       temp[i] = (temp[i+1]+arr[i])%mx;
   }
    sum=0;
   for(int i=1;i<=n; ++i){
       sum += ((temp[i]%mx)*(arr[i-1]%mx))%mx;
   }
   cout<<sum%mx<<endl;

}