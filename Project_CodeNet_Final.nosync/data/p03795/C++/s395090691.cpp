#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

using namespace std;

int main(){
  int N; cin >> N;
  cout << (N*800)-(N/15*200) << endl;
}