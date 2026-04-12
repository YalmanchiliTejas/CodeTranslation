#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
  }
  int count=0,anscount=0;
  for(int i=0;i<n;i++){
    for(int k=0;k<=i;k++){
      if(vec.at(k)<=vec.at(i)){
        count++;
      }
    }
    if(count>=i+1){
      anscount++;
    }
      count=0;
  }
  cout<<anscount<<endl;
}