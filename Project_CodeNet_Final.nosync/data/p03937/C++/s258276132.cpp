#include <bits/stdc++.h>
using namespace std;
int main()
{
  int h,w;
  cin>>h>>w;
  vector<string>s(h);
  for(int i=0;i<h;i++)
  {
    cin>>s[i];
  }
  int count=0;
  for(int i=0;i<h;i++)
  {
    for(auto x:s[i])count+=(x=='#');
  }
  if(count==(h+w-1))cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}