#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin>>a;
  vector<int> vec(a);
  
  for(int i=0;i<a;i++){
    cin>>vec.at(i);
  }
  int answer=1;
  int gg=0;
    for(int i=1;i<a;i++){
      for(int j=0;j<i;j++){
        if(vec.at(j)>vec.at(i)){
          gg++;
        }
      }
      if(gg==0){
      answer++;
      }
      gg=0;
    }
  cout<<answer<<endl;
}