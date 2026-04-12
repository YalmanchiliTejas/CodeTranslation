#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i;
    string s;
    cin>>s;
    s='#'+s;
    int k;
    cin>>k;
    char ch=s[k];
    for(i=1;i<=n;i++)
    {
        if(s[i]!=ch)
        {
            s[i]='*';
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}

