#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int count_a=0,count_b=0;
  int ans=1;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A'){
      count_a++;
    }
    else
    {
      count_b++;}}
  if(count_a ==0 || count_b==0)
  {ans=0;
  }
  if(ans)
  {cout<<"Yes"<<endl;
  }
  else
  {cout<<"No"<<endl;
  }
  return 0;
}