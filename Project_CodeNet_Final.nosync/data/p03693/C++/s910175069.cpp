#include <iostream>
#include <string>
#include <vector>
#define REP(i,k,n) for(int(i)=(k);(i)<(n);++(i))
using namespace std;

int main()
{
  int r,g,b;
  cin >> r >> g >> b;

  int n = r * 100 + g * 10 + b;
  string ans = (n % 4 == 0) ? "YES" : "NO";
  cout << ans << endl;

  return 0;
}
