#include <bits/stdc++.h>
using namespace std;
#define int long long 
void print(int arr[], int n){
     for(int i=0;i<n;++i)
     cout<<arr[i]<<" ";
     cout<<endl;
}
int gcd(int a,int b){
    if(a==0)
    return b;
    return gcd(b%a,a);
}
int32_t main()
{
     int n,c=1;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;++i)
     cin>>arr[i];
     int mx=arr[0];
     for(int i=1;i<n;++i){
         if(arr[i]>=mx){
             mx=arr[i];
             c++;
         }
     }
     cout<<c;
    return 0;
}
