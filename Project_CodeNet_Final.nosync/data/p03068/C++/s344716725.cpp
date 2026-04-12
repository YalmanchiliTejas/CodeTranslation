#include<bits/stdc++.h>
using namespace std;
#define il inline
#define rg register
#define ll long long
#define CL(a,b) memset(a,b,sizeof a)
int main()
{
    char s[11];
    int n,k;
    cin>>n>>s>>k;
    for(int i=0;i<n;i++)
        if(s[i]!=s[k-1])
        s[i]='*';
    cout<<s;
    return 0;
}

