#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int H[N];
  for(int i=0;i<N;i++)
  {
    cin >> H[i];
  }

  bool judge;
  int total = 1;

  for(int i=1;i<N;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(H[i]>=H[j])
      {
        judge = true;
      }
      else
      {
        judge = false;
        break;
      }
    }
    if(judge)total += 1;
  }

  cout << total << endl;

  return 0;
}