// AOJ 1147
#include<iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n;
  while (cin >> n and n) {
    int sum = 0, mxm = -1e5, mnm = 1e5;
    REP(i, n) {
      int s;
      cin >> s;
   
      if (mxm < s) mxm = s;
      if (mnm > s) mnm = s;
   
      sum += s;
    }
   
    cout << (sum - mxm - mnm) / (n - 2) << endl;
  }
}