#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    vector<int> c(26,100);

    for(int i=0;i<n;i++)
    {
        str s;cin>>s;

        vector<int> bc(26,0);
        for(int j=0;j<s.size();j++)bc[s[j]-'a']++;
        for(int j=0;j<26;j++)c[j]=min(c[j],bc[j]);
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<c[i];j++)cout<<(char)(i+'a');
    }

    return 0;
}
