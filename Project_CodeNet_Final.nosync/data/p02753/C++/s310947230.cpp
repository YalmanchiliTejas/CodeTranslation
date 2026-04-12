#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    lli a=0,b=0,i;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='A')
         a++;
        else if(s[i]=='B')
          b++;
    }
    if(a==3 || b==3)
     cout<<"No"<<"\n";
    else 
      cout<<"Yes"<<"\n";
}