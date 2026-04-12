#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
int main(){
   int n;
   long long sum=0,s=0;
   long long a[200005];
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>a[i];
       s+=a[i];
       s%=MOD;
   }
   for(int i=0; i<n; i++){
        s-=a[i];
        if (s < 0) s += MOD;
        sum+=a[i]*s;
        sum%=MOD;
   }

   cout<<sum<<'\n';
   return 0;
}