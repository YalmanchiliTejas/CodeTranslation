#include<bits/stdc++.h>

using namespace std;

int main()
{
  char s[3];
  cin>>s;
  char z=s[0];
  int count=1;
  for(int i = 1 ; i< 3;i++)
  if(z==s[i])count++;

  if(count==3)cout<<"No";
  else cout<<"Yes";
}
