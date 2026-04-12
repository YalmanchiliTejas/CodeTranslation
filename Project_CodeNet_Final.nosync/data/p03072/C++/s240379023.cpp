#include <bits/stdc++.h>
using namespace std;
int main() { 
   long long n;
   cin>>n;
   vector<long> h(n);
   for(int i=0;i<n;i++){
     cin>>h[i];
   }
   long ans=0;
   for(int i=0;i<n;i++){
     long bad=0;
     for(int j=0;j<i;j++){
       if(h[i]<h[j]){
         bad++;
         break;
       }
     }
     if(bad==0){
       ans++;
     }
   }
   cout<<ans<<endl;
     
}
