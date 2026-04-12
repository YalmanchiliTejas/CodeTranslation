#include<iostream>

using namespace std;
int main()
{
  int n;
  int h[20];
  
  cin >> n;

  for (int i = 0; i < n; i++)
  {
	cin >> h[i];
  }
  
  int max = 0;
  int count = 0;
  
  for (int i = 0; i < n; i++)
  {
    if (i == 0){
      count++;
      continue;
    }
    else
    {
      bool result = true;
      for(int j = 0; j < i; j++)
      {
        if (h[i] < h[j])
        {
          result = false;
          break;
        }
      }  
      if (result)
      {
        count++;
      }
    }
  }
  cout << count;
  
    return 0;
}