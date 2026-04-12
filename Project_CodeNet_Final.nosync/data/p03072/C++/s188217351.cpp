#include <bits/stdc++.h>
using namespace std;


  
int main(){
  long n,m,count;
  cin >> n;
  vector<int> v(n);
  count = 1;
  if(n>1){
  for(long i ; i < n ; i++){
    cin >> v.at(i);
  }
  m = v.at(1);
  for(long j = 1; j < n; j++){
    if(v.at(j) >= v.at(j-1)){
      m = v.at(j);
      count++;
    }
    if(v.at(j) < v.at(j-1))
       v.at(j) = v.at(j-1);
  }
  }
  cout << count << endl;
      }