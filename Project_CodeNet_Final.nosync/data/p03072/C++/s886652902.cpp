#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
   cin >> N;
  int count=N;
   vector<int>yama(N);
  
  for(int i=0;i<N;i++){
   cin >> yama.at(i);
  }
  
  for(int i=0;i<N;i++){
     for(int j=0;j<i;j++){
       if(yama.at(i)>=yama.at(i-j-1)){
       }
       else{
         count--;
         break;
       }
     }
  }
  
  
  cout << count << endl;
}