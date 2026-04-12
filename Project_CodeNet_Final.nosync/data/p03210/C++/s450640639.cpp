#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
int main() {
  int n;
  stringstream ss;
  cin >> n;
  string ans = (n==3 || n==5|| n==7)?"YES":"NO";
  cout << ans<< endl;
  return 0;
}
