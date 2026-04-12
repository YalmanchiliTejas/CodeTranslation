#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,i,j;
    cin>>n;
    string s;
    int hash[n][26];
    memset(hash,0,sizeof(hash));
    for (i=0;i<n;i++)
    {
        cin>>s;
        for (j=0;j<s.size();j++)
            hash[i][s[j]-'a']++;
    }
    int com;
    string ans="";
    for (j=0;j<26;j++)
    {
        com=hash[0][j];
        for (i=0;i<n;i++)
            com=min(com,hash[i][j]);
        for (i=0;i<com;i++)
            ans+=(char)(97+j);
    }
    cout<<ans<<endl;
}