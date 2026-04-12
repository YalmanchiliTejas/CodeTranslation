#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  multiset<long> primary; 

  int trans, curr; 
  cin >> curr; 
  primary.insert(-1); 
  primary.insert(curr);
  primary.insert(LONG_MAX); 


  for (int i = 1; i < N; i++){
    cin >> curr; 
    auto it = --primary.lower_bound(curr); 
    if(*it == -1){
        primary.insert(curr); 
    } else  {
        primary.erase(it);
        primary.insert(curr); 
    }
    
  }  
  cout << primary.size() - 2; 
}
