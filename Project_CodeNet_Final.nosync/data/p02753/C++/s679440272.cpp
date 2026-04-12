#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int count = 0;
  for(char j:s){
    if(j=='A'){
      count++;
    }
  }
    if(count==0 || count == 3){
      cout<<"No";
    }
      else{
        cout<<"Yes";
      }
  }