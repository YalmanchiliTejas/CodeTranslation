#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
   int n,k;
   cin>>n;
   string s;
   cin>>s;
   cin>>k;
   char t=s[k-1];
   for(int i=0;i<n;++i){
       if(s[i]!=t)
       s[i]='*';
   }
   cout<<s;
   return 0;
}