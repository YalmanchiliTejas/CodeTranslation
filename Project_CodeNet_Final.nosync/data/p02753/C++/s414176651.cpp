#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int ,int> pairs;
int main()
{
    ll n,weight,value,a=0,b=0;
  string s;
  char c;
  cin>>s;
  for(int i=0;i<3;i++)
  {
      c=s[i];
      if(c=='A')
      {
          a++;
      }
      else b++;
  }
  if(a<=2&&a!=0)
  {
      cout<<"Yes"<<endl;
  }
  else
    cout<<"No"<<endl;
}
