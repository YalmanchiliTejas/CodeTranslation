#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  string ans = "Yes";
  if(m!=n){
	ans = "No";
  }
  cout << ans;
  
  return 0;
}