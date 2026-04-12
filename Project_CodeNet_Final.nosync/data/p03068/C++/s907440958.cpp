#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int k,n;
    cin>>n;
    string s;
    cin>>s;
    cin>>k;
    for(int i=0;i<n;i++)
        if(s[i]!=s[k-1])
        s[i]='*';
        cout<<s<<'\n';
        return 0;
}
