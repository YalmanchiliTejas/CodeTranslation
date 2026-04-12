#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,count=0;
  cin >> N;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
  }
  for(int i=0;i<N;i++){
    bool a=false;
    for(int j=0;j<i;j++){
      if(H.at(j)>H.at(i)){
        a=true;
      }
    }
    if(!a){
      count++;
    }
  }
  cout << count << endl;
} 