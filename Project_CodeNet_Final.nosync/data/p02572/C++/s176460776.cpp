#include<bits/stdc++.h>
using namespace std ; 
const int N= 3e5;
int Mod = 1e9+7 ; 
long long cum [N];
int main(){
        int n ; 
        cin>>n;
        long long arr[n];
        for(int i =0;i<n;i++){
                cin>>arr[i]; 
             
         }
       for(int i =n-1;i>=0;i--){
               cum[i]+=(cum[i+1]+arr[i])%Mod; 
       }

       long long sum =0; 
       for(int i =0;i<n;i++)sum+=arr[i]*cum[i+1]%Mod; 
       cout<<sum%Mod ; }