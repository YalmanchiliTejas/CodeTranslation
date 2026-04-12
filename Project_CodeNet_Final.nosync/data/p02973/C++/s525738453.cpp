#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int MAX = 2001;
const int MOD = 1000000007;
 
 



 
signed main(){
    int n,ok,ng,mid;
    cin>>n;
   int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   vector<int> k;
   k.push_back(a[0]);
   for(int i=1;i<n;i++){
       if(k[0]>=a[i]){
       ok =0;
       ng =k.size();
       while(abs(ok-ng)>1){
           mid =(ok+ng)/2;
           if(k[mid]>=a[i]){
               ok=mid;
           }else ng=mid;
       }
       if(ok>=k.size()-1)k.push_back(a[i]);
       else {
           k[ng]=a[i];
        ;}
       }else{
           k[0]=a[i];
       }
   }
   cout<<k.size();

    return 0;
}