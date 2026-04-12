#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int flag=0,f=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
          if(s[i]=='A')
          {
               flag++;
          }
          else
          {
                f++;
          }
    }

    if(f==0||flag==0)
      cout<<"No"<<endl;
        else
      cout<<"Yes"<<endl;
}
