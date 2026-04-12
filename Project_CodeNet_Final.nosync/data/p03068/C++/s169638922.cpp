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
    int n,k,i;
    cin>>n;
    string s;
    cin>>s;
    cin>>k;
    for (i=0;i<n;i++)
    {
        if (s[i]!=s[k-1])
            cout<<'*';
        else
            cout<<s[i];
    }
}