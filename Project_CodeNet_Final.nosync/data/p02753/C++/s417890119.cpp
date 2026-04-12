#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int a=0,b=0; char c;
  for(int i=0;i<3;i++)
  {
    cin>>c;
    if(c=='A') a++;
    else b++;
  }
  if(a==1 || b==1) cout<<"Yes";
  else cout<<"No";
    return 0;
}
