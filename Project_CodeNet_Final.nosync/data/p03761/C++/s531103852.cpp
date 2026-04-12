#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s,x;
    vector <int> a(26,0);
    cin>>s;
    for(int i=0;i<s.size();i++) a[s[i]-'a']++;
    for(int i=0;i<n-1;i++)
    {
        cin>>x;
        vector <int> b(26,0);
        for(int j=0;j<x.size();j++)
            b[x[j]-'a']++;
        for(int j=0;j<26;j++)
            a[j]=min(a[j],b[j]);
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<a[i];j++)
        {
           cout<<(char)(i+'a');
        }

    return 0;
}
