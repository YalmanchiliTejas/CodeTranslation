#include<bits/stdc++.h>
using namespace std;

int main(){
  string a;
  cin >> a;
  int b=0,c=0;
  for(int i=0;i<3;i++){
    if(a.at(i)=='A'){
      b++;
    }
    if(a.at(i)=='B'){
      c++;
    }
  }
  if(b==3 || c==3)cout << "No" <<endl;
  else{
    cout<<"Yes"<<endl;
  }
}
