#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  vector<int>b(a);
  for(int i=0;i<a;i++){
    cin>>b.at(i);
  }
  int c=1;
  int d=b.at(0);
  for(int i=1;i<a;i++){
    if(b.at(i)>=d){
      c++;
      d=b.at(i);
    }
  }
  cout<<c;
}