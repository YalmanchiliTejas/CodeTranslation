#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;cin>>N;
  vector<int> H(N+1);
  for (int i=1;i<=N+1;i++)
     cin>>H[i];
  
  int max=0;
  int count=0;
  for (int i=1;i<=N;i++)
  {
    if (H[i]>=max)
    {
      count++;
      max = H[i];
    }
  }
    
  cout<<count<<endl;
}