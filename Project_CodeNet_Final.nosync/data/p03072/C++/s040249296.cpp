#include<iostream>
using namespace std;

int main()
{
  int n, flag;
  int ans = 1;
  cin >> n;
  int h[110];
  for (int i=0;i<n;i++){
    cin >> h[i];
  }
  for(int i=1;i<n;i++)
  {
    flag = 0;
    for (int j=0;j<i;j++)
    {
      if(h[i] < h[j])
      {
        flag = 1;
      }
    }
    if(flag == 0)
    {
      ans += 1;
    }
  }
  cout << ans;
  return 0;
}
