#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long int LL;
typedef vector<int> VI;

int main() {
  int N;
  cin >> N;
  int ret = 0, maxH = 0;
  REP(i, N) {
    int H;
    cin >> H;
    if(H >= maxH) {
      ret++;
      maxH = H;
    }
  }
  cout << ret << endl;
}