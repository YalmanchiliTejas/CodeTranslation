#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,e;
  cin >> a;
  vector<int>vec;
  for(int b = 0;b<a;b++){
    cin >> e;
  	vec.push_back(e);
  }
  int c = 1;
  int f = vec.at(0);
  for(int d =1;d<a;d++){
  if(vec.at(d)>=f){
  c++;
  f =vec.at(d);
  }
  
  
  }
  
  cout << c << endl;

}