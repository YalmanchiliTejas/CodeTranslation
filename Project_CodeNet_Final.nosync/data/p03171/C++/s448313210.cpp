#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long getXY(vector<long> elements)
{ 
  int n = elements.size();
  
  vector< vector<long long> > xy(n, vector<long long>(n, 0));
  
  for(int gap=0; gap<n; gap++)
  {
    for(int i=0; i<n && i+gap<n; i++)
    {
      int j = i+gap;
      if(i == j)
        xy[i][j] = elements[i];
      else
        xy[i][j] = max( elements[i] - xy[i+1][j], elements[j] - xy[i][j-1]);
    }
  }
  
  return xy[0][n-1];
}

int main()
{
  int n;
  cin >> n;
  
  vector<long> elements(n);
  
  for(int i=0; i<n; i++)
  {
    cin >> elements[i];
  }
  
  cout << getXY(elements) << endl;
  
  return 0;
}