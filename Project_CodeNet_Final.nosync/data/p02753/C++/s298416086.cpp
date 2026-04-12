#include<bits/stdc++.h>
using namespace std;
 
int main(){
  string str;
  cin >> str;
  if (str[0]==str[1] && str[1]==str[2] && (str[2]=='A' || str[2]=='B')){
    cout<<"No"<<endl;
    return 0;
  }
  cout <<"Yes" <<endl;
}