#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, counter = 1;
  cin >> n;
  
  vector<int> h(n);
  for(int i = 0;n > i;i++)
    cin >> h.at(i);
  
  for(int i = 1;n > i;i++){
    for(int j = 0;i > j;j++){
      if(h.at(i) - h.at(j) < 0)
        break;
      if(j == i -1)
        counter++;
    }
  }
  
  cout << counter << endl;
}