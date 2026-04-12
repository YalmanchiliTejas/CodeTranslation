#include<bits/stdc++.h>
using namespace std;

int main()
{
  char s[3];
  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < 3; i++)
  {
	cin>>s[i];
    if(s[i] == 'A')
      sum1++;
    else if(s[i] == 'B')
      sum2++;
  }
  if(sum1 == 3 || sum2 == 3)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  return 0;
}           
 