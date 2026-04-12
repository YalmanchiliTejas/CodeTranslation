#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
  string s;
  cin>>s;
  ll a=0,b=0;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A')
       a++;
       else
       b++;
       }
       if(a==0||b==0)
       cout<<"No";
       else
       cout<<"Yes";
       }