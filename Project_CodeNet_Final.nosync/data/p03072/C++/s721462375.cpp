#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int inn[100] = {0};

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i ++)
    cin >> inn[i];

  int ans = 0;
  for (int i = 0 ; i  < N; i++)
  {
      int cansee = 1;
      for (int j = 0; j < i; j++)
      {
          if (inn[j]>inn[i])
            cansee = 0;
      }
      if (cansee)
        ans++;
  }
  cout << ans << endl;
  return 0;
}
