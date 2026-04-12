#include <bits/stdc++.h>

using namespace std;

int main()
{
 	int n;
  cin>>n;
  string s;
  cin>>s;
  int k;
  cin>>k;
  k--;
  char ofc=s[k];
 
  for(int i=0; i<n; i++)
  {
   	if(i==k) continue;
    else
    {
     	if(s[i]!=ofc)
        {
         	s[i]='*';
        }
    }
  }
  cout<<s<<endl;
  return 0;
}
