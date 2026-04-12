#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  int counter = 1;
  for(int i=1;i<N;i++){//今主役のホテル。ホテル１(i=0)は確かめない。
    bool good_view = true;
    for(int j=0;j<i;j++){//比較対象のホテル。
      if(A.at(j)>A.at(i)){
        good_view = false;
        break;
      }
    }
    if(good_view){
      counter++;
    }
  }
  cout << counter << endl;
}