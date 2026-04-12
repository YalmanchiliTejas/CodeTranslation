#include <bits/stdc++.h>
using namespace std;


int main(){
    string S;
   cin>>S;
   bool allA=true,allB=true;
   for(int i=0;i<3;i++){
       if(S.at(i)=='A'){
           allB=false;
       }
       if(S.at(i)=='B'){
           allA=false;
       }
   }
   if(allA||allB){
       cout<<"No"<<endl;
   }
   else{
       cout<<"Yes"<<endl;
   }
}
