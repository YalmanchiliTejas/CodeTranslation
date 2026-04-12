#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n,k,i;
  string s,t;
  cin >> n;
  cin >> s;
  cin >> k;
  t=s.substr(k-1,1);
  for(i=0;i<n;i++)
    if(s.substr(i,1)!=t)
      s.replace(i,1,"*");
  cout << s << endl;
  return 0;
}