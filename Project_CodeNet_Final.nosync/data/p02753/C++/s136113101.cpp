
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{


  string s;
  cin>>s;
  int a=0,b=0;
  for(int index=0;index<s.size();index++)
    if(s[index]=='A')
    a++;
  else
    b++;

  if(!a||!b)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;



    return 0;
}
