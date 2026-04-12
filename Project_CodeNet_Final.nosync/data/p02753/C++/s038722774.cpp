#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int c=0,b=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')
        {
            c++;
        }
        else if(s[i]=='B')
        {
            b++;
        }
    }
    if(c >=1 && b>=1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;

}
