#include <iostream>
#include <string>
using namespace std;
typedef long long LL;

int main(){
  string S;
  cin >> S;
  cout << (S == "AAA" || S == "BBB" ? "No" : "Yes") << endl;
}