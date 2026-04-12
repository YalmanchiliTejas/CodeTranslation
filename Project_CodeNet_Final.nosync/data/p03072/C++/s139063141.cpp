#include <iostream>
using namespace std;

int main()
{
  int n, ans = 0, max = 0;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int h;
    cin >> h;
    if(h >= max)
    {
      ans++;
      max = h;
    }
  }
  
  cout << ans << endl;
  return 0;
}