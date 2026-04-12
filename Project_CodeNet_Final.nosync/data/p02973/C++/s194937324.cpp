#include <bits/stdc++.h>
using namespace std;

int main(){

  int N; cin >> N;
  
  vector<int> A(N);
  for(int i=0; i<N; i++)
    cin >> A.at(i);
  
  vector<int> flag(1);
  flag.at(0) = A.at(0);
  
  for(int i=1; i<N; i++){
    if(A.at(i) <= flag.at(flag.size()-1)){
      flag.push_back(A.at(i));
      continue;
    }else if(A.at(i) > flag.at(0)){
      flag.at(0) = A.at(i);
      continue;    
    }else if(A.at(i) > flag.at(1)){
      flag.at(1) = A.at(i);
      continue;
    }
     
    int right = flag.size()-1;
    int left = 0;
    while(right-left != 1){
      if( flag.at((right+left)/2) >= A.at(i) )
        left = (right+left)/2;
      else
        right = (right+left)/2;
    }
    flag.at(right) = A.at(i);
  }

  cout << flag.size() << endl;

}