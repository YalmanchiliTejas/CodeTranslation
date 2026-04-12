#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
   string s;
   cin>>s;
   
   for(int i=1;i<3;i++){
       if(s[i]!=s[i-1]){
           cout<<"Yes";
           return 0;
       }
   }
   cout<<"No";


}