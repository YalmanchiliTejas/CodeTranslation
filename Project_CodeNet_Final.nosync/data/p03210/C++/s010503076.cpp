#include <iostream>
#include <string>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
  int N;
  cin >> N;
  if(N == 3 || N == 5 || N == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}