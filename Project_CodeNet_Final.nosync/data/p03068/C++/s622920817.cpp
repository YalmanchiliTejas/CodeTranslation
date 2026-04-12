#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,k;
    cin>>n;
    cin>>s;
    cin>>k;
    for(int i=0;i<n;i++)
    
    {
        if(s[i]!=s[k-1]) s[i]='*';
    }
    for(int i=0;i<n;i++)
    cout<<s[i];
    return 0;
}