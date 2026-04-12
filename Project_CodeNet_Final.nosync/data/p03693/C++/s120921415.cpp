#include<bits/stdc++.h>
using namespace std;
 
int main(){
  string s = "111";
  for(int i=0;i<3;i++){
    cin >> s.at(i);
  }
  int num = stoi(s);
  
  if(num % 4 == 0){
    cout << "YES"<<endl;
  }else{
    cout << "NO" << endl;
  }
}