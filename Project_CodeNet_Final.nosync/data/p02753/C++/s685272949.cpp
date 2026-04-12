#include<iostream>
using namespace std;
int main()
{
char s[100];
 int i;
  for(i=1;i<=3;i++)
  {
    cin>>s[i];
  }
if(s[1]==s[3] and s[2]==s[3])
  cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  return 0;
}