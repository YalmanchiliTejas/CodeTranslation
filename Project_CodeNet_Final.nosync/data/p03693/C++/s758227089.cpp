#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int x , a , b;
  cin >> x >> a >> b;
  int k = a * 10 + b;
  if(k % 4 == 0)cout << "YES" << endl;
  else cout << "NO" << endl;
}