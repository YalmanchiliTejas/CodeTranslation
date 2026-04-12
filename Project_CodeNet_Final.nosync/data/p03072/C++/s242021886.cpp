#include <bits/stdc++.h>
using namespace std;
 

int main() 
{
  int i,S,L;
  cin >> i;
  vector<int> vec(i);

  for (int j = 0; j < i; j++) 
  {
    cin >> vec.at(j);
  }
  S = 1;
  L = vec.at(0);
  for(int j =1; j<i ;j++)
  {
    if(L<=vec.at(j))
    {
      S++;
      L = vec.at(j);
    }
  }
    cout << S <<endl;
}