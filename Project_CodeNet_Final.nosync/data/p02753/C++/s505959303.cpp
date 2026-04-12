#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char s[5];
  cin>>s;
  if(strcmp(s,"AAA")==0||strcmp(s,"BBB")==0)
    cout<<"No";
  else
    cout<<"Yes";
  return 0;
}
