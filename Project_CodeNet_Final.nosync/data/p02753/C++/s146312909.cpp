#include<bits/stdc++.h>
using  namespace std;
#define ll long long int
int main()
{
   string s;
   cin>>s;
  ll a=0,b=0;
  for(ll i=0;i<3;i++)
  {
      if(s[i]=='A')
        a++;
      if(s[i]=='B')
        b++;

  }
  if(a>0&&b>0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
    return 0;
}
