#include <bits/stdc++.h>
using namespace std;
int main() {
    
    
    
   int n;
   cin>>n;
   
   vector<int> v(n);
   
   for(int i=0;i<n;++i)
       cin>>v[i];
       
    reverse(v.begin(),v.end());
     
     int ct,ct1=1;;
      for(int i=0;i<n-1;++i){
          ct=0;
          for(int j=i+1;j<n;++j){
              if(v[i]>=v[j])
                ct++;
          }
          if(ct==n-1-i)
             ct1++;
      }
       
      
      cout<<ct1;
    
    //for(auto it=v.begin();it!=v.end();++it)
      // cout<<*it<<" ";
 return 0;
}