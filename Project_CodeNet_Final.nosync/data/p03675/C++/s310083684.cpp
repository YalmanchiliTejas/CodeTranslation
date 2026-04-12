#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n;cin >> n;
  int a;
  deque <int> b;
  for(int i=0;i<n;i++)
  {
    cin >> a;
    if(i%2==0)
    {
      b.push_back(a);
    }else
    {
      b.push_front(a);
    }

  }
  if(n%2==0)
  {
    for(auto i=b.begin();i!=b.end();i++)
    {
      cout << *i;
      if(i!=b.end()-1)
      {
        cout <<" ";
      }
    }
  }
  else
  {
    for(auto i=b.end()-1;i!=b.begin()-1;i--)
    {
      cout << *i;
      if(i!=b.begin())
      {
        cout <<" ";
      }
    }
  }


  
  cout << "\n";
  return 0;
}
