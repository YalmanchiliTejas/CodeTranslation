#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  string s;
  cin>>s;
  bool a=0,b=0;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A')
      a=1;
    if(s[i]=='B')
      b=1;
  }

  if(a && b)
  {
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }
  return 0;
}