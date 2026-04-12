#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int cnt=0;
  cin>>n;
  vector<int> mt(n);
  for(int i=0;i<n;i++){
    cin>>mt.at(i);
  }
  int sun=mt.at(0);
  for(int i=0;i<n;i++){
    if(sun<=mt.at(i)){
      cnt++;
      sun=mt.at(i);
    }
  }
  cout<<cnt<<endl;
}