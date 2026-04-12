#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
int main()
{
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  ll a=0,b=0;
  for(int i=0;i<=2;i++)
  {
    if(s[i]=='A')
    a++;
    else
    b++;
  }
  if(a==3 || b==3)
  {
   cout<<"No";
  }
  else
  {
   cout<<"Yes";
  }
  return 0;
}