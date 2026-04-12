#include <iostream>
using namespace std;
int h[20];
int main()
{
  int n,br=0;
  cin >> n;
  for(int i=0;i<n;i++)
    cin>>h[i];
 int max=0;
  for(int i=0;i<n;i++)
  {
    if(h[i]>=max)
    {
      max=h[i];
      br++;
    }
  }
  cout << br;
}