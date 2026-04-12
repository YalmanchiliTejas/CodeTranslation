#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> vec(20);
  for(int i = 0; i < n; i++){
    cin >> vec.at(i);
  }
  
  int count;
  count = n;
  
         for (int i = 1; i < n; ++i) {
          for (int j = 0; j < i; j++){
            if(vec.at(i) < vec.at(j)){
              count--;
              break;
            }
          }
         }
  cout << count << endl;
}

        
 