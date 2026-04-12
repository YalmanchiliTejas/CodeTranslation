#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  string s; 
  cin>>s;
  int a = 0, b=0;
  for(int i = 0 ; i < 3;  i++)
   {
        if(s[i]=='A')
            a++;
        else
            b++;
    }
    if(a==1||b==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    
  return 0;
}