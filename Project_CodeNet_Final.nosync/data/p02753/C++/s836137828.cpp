#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,l,c=0,d=0,i;
    string s;
    cin>>s;
    l= s.size();
    for(i=0;i<l;i++)
    {
        if (s[i]=='A')
                c++;
        else
            d++;
    }
    if(c>0 && d>0)
        cout<<"Yes";
    else
        cout<<"No"<<endl;
    return 0;
}
