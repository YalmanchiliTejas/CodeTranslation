#include<iostream>
#include <vector>
#include <cstdlib>
#include<algorithm>
#include<string>
#include<cmath>
#include<math.h>
#include <list>
#define ll long long 
using namespace std;
ll md=1000000007;




int main()
{
 ll n;
 cin>>n;
 vector <ll> arr;
 ll sum=0;
 for(ll i=0;i<n;i++)
 {
   ll temp;
   cin>>temp;
   sum+=temp;
   arr.push_back(temp);
 }
 ll ans=0;
 for(ll i=n-1;i>=0;i--)
 {
   sum-=arr[i];
  // ans+=(sum*arr[i]);
   ans=(ans%md + ((sum%md)*(arr[i]%md))%md)%md;


 }
 cout<<ans%md;
 return 0;
}