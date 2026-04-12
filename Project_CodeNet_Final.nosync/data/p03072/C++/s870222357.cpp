#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int mountCnt = 0;
  
  
  cin >> mountCnt;
  int viewCnt = mountCnt;
  int z = mountCnt;
  vector<int> vec(mountCnt);
  for(int i=0;i<mountCnt;i++){
    cin >> vec.at(i);
  }
  for(int i=0;i<mountCnt;i++){
    if(i == 0)continue;
    for(int j=0;j<i;j++){
      if(vec.at(i) < vec.at(j)){
        viewCnt--;
        break;
      }
       }
    }
    
       cout << viewCnt << endl;
       
}