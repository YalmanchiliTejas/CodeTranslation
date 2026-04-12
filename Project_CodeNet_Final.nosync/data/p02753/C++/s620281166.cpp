#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int p=0,c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')
        {
            c++;
        }
        else
        {
            p++;
        }
    }
    if(p==0||c==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }



    return 0;
}
