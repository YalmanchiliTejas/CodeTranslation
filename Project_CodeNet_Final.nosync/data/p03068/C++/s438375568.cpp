#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;string s;cin>>n>>s>>k;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (s[i]!=s[k-1])
        {
            /* code */
            s[i]='*';
        }
        
    }
    cout<<s<<endl;
}