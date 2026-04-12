#include <iostream>
using namespace std;

int main()
{
  int n, m;
  
  while (cin >> n >> m, n || m){
    int maxn = n + m;
    char s = 'A', store = s;
    for (int i = 1; i < 5; i++){
      cin >> n >> m;
      int sum = n + m;
      if (maxn < sum){
        maxn = sum;
        store = s + i;
      }
    }
    cout << store << ' ' << maxn << endl;
  }
 
  return (0);
}