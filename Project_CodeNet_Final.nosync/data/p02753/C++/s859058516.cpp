#include <bits/stdc++.h>
using namespace std;
 
int main() {

 vector<char> ore(3);
  for(int i=0;i<3;i++){
    cin>>ore.at(i);
  }
 if(ore.at(0)==ore.at(1)&&ore.at(1)==ore.at(2)){
   cout<<"No"<<endl;
 }else{
   cout<<"Yes"<<endl;
 }
}