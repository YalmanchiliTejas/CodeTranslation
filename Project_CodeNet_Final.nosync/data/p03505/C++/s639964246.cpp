#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  ll k,a,b;
  
  cin >> k >> a >> b;
  
  if (a>b){
    cout << (k-b-1)/(a-b)*2+1 << endl;
  }else{
    if (k<=a){
      cout << 1 << endl;
    }else{
      cout << -1 << endl;
    }
  }
  
  return 0;
}