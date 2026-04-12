#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,L;
  
   vector<char>str(3);
  
    for(int i=0; i<3; i++){
        cin>>str.at(i);
     }
  int count=0;
    for(int i=0; i<3; i++){
        if(str.at(i)=='A')
          count++;
    }
  if(count==3 || count==0)
    cout << "No";
  else
    cout << "Yes";
}