#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int main()
{
    cin>>n>>s>>k;
    char x=s[k-1];
    for(int i=0;i<n;i++)
    {
        if(s[i]==x)
            continue;
        else s[i]='*';
    }
    cout<<s;
}
