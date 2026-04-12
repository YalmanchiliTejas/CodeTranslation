#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,result,highest;
  cin >> n;
  result = 0;
  highest = 0;
  vector<int> hotel(n);
  for(int i = 0;i<n;i++){
    cin  >> hotel[i];
  }
  
  for(int i = 0;i<n;i++){
    if(hotel[i] >= highest){
      result += 1;
      highest = hotel[i];
    }
  }
  cout << result << endl;
}