#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  string s;
  cin>>s;
  int n =s.length();
  if(n==1 || n==0)
  {
    cout<<"No"<<endl;
    return 0;
  }
  for(int i =0;i<n-1;i++)
  {
      if(s[i]!=s[i+1])
      {
        cout<<"Yes"<<endl;
        return 0;
      }
  }
  cout<<"No"<<endl;
}
