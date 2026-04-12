#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int *h = new int[n];
  for (int i = 0; i < n; i++)
    cin >> h[i];
  
  int sum = 1;
  for (int i = 1; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++) {
      if (h[j] > h[i]) {
        flag = false;
        break;
      }
    }
    if (flag)
      sum++;
  }
  cout << sum << endl;
  
  delete h;
  
  return 0;
}