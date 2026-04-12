#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int answer = 0;
  int N = 0;
  cin >> N;
  
  vector<int> H(N);
  for (int i = 0; i < N; i ++)
  {
    cin >> H[i];
  }
  
  int tmp_h = 0;
  for (int i = 0; i < N; i ++)
  {
  	if (i == 0)
    {
      ++ answer;
      tmp_h = H[i];
    }
    else
    {
      if (H[i-1] <= H[i] && tmp_h <= H[i])
      {
        ++ answer;
        tmp_h = H[i];
      }
    }
  }
  
  cout << answer << endl;
}