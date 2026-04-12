#include <bits/stdc++.h>
using namespace std;

int main(){

  int N; cin >> N;
  
  vector<int> A(N);
  for(int i=0; i<N; i++)
    cin >> A.at(i);
  
  vector<int> flag;
  flag.push_back(A.at(0));
  
  for(int i=1; i<N; i++){
    
    if(flag.at(0) >= A.at(i)){
      flag.insert(flag.begin(),A.at(i));
      continue;
    }
    
    auto it = lower_bound(flag.begin(),flag.end(),A.at(i));
    *(it-1) = A.at(i);

  }
  
  cout << flag.size() << endl;
  
  
}