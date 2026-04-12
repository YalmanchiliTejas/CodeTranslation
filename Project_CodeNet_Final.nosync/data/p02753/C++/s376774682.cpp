#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    string s;
    cin>>s;
    int l=s.length();
    int a=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='A')
        {
            a++;
        }
    }
    if(a==0 || a==l)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
    
    return 0;
}    