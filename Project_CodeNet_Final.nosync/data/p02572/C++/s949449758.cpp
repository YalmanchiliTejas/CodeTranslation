#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll gcd(ll a, ll b);
int main(){
cin.tie(0);
ll n,a[200000],sum=0,result=0;
cin>>n;
for(ll i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    sum%=(1000000000+7);
}
sum-=a[0];

for(ll i=0;i<n-1;i++){
    result+=a[i]*sum;
    result%=(1000000000+7);
    sum=(sum-a[i+1]+1000000000+7)%(1000000000+7);

}
  if(result<0)result+=(1000000000+7);
cout<<result;

return 0;
}






ll gcd(ll a, ll b){

   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }

}