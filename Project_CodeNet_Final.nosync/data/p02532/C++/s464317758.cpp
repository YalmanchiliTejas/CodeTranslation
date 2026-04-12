#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;

int main(){
  int n, p, q, b[100];
  string x;
  cin >> n;
  char a[100][1000];

  for (int i = 0; i < 100; i++) b[i] = 0;
  
  while (cin >> x) {
    if (x == "quit") {
      break;
    }else if (x == "push") {
      cin >> p;
      cin >> a[p - 1][b[p - 1]];
      b[p - 1]++;
    }else if (x == "pop") {
      cin >> p;
      b[p - 1]--;
      cout << a[p - 1][b[p - 1]] << endl;
    }else {
      cin >> p >> q;
      b[p - 1]--;
      a[q - 1][b[q - 1]] = a[p - 1][b[p - 1]];
      b[q - 1]++;
    }
  }
  return 0;
}