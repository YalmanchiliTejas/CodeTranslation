#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  
  int x , y , z ;
  cin >> x >> y >> z ;
  
  int sum=z;
  int c=0;
  while(x-(y+z)>=sum){
    sum+=y+z;
    c++;
  }
  
  cout << c << endl;
}