#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  
 if(S.at(0)=='A'){
   if(S.at(1)=='A'&&S.at(2)=='A'){
     cout<<"No"<<endl;
   }
   
   if(S.at(1)=='B'||S.at(2)=='B'){
     cout<<"Yes"<<endl;
   }
 }
  
 if(S.at(0)=='B'){
   if(S.at(1)=='B'&&S.at(2)=='B'){
     cout<<"No"<<endl;
   }
   
   if(S.at(1)=='A'||S.at(2)=='A'){
     cout<<"Yes"<<endl;
   }
 }
}