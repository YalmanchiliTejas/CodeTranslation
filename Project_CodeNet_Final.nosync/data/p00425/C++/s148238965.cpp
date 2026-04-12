#include <iostream>
#include <string>
using namespace std;

int a, b, c;

int solve(string s) {
  int tmp;
  if(s == "North") tmp = a, a = b, b = 7-tmp;
  if(s == "East")  tmp = c, c = a, a = 7-tmp;
  if(s == "West")  tmp = a, a = c, c = 7-tmp;
  if(s == "South") tmp = b, b = a, a = 7-tmp;
  if(s == "Right") tmp = b, b = c, c = 7-tmp;
  if(s == "Left")  tmp = c, c = b, b = 7-tmp;
  //cout << a << endl;;
  return a;
}

int main() {
  string str;
  int n, sum;
  while(cin >> n, n) {
    a = 1; b = 2; c = 3;
    sum = 1;
    for(int i = 0 ; i < n ; i++) {
      cin >> str;
      sum += solve(str);
    }
    cout << sum << endl;
  }
  return 0;
}