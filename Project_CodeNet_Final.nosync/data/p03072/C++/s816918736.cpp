#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int tmp;
  int max = 0;
  int count = 0;
  for (int i = 0; i < n; i ++)
  {
    cin >> tmp;
    if (tmp >= max)
    {
      max = tmp;
      count ++;
    }
  }
  
  cout << count << endl;
  return 0;
}