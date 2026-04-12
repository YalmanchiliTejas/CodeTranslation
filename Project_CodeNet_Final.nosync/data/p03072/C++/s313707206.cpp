//B Great Ocaen View
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,ans,standard;
  cin>>n;
  ans=1;
  vector<int> h(n);
  for(int i=0;i<n;i++)
  {
    cin>>h.at(i);
  }
  standard=h.at(0);
  for(int i=1;i<n;i++)
  {
    if(standard<=h.at(i))
    {
      standard=h.at(i);
      ans++;
    }
  }
  cout<<ans<<endl;
}
