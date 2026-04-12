#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ac=0;
    int bc=0;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]=='A')
        {
            ac++;
        }
        else
        {
            bc++;
        }
    }
    if(ac==0 || bc==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}