#include<bits/stdc++.h>
#define     fast                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     ll                      long long
#define     pb                      push_back
#define     M                       1000000007
using namespace std;
int main()
{
    ll p,q,x,y,sum=0;
    cin>>p>>q;
    vector<string> v;
    map<int,int>mp,mpt;
    int n = p;
    while(n--)
    {
        string s;
        cin>>s;
        v.pb(s);
    }


    for(ll i=0; i<p; i++)
    {
        int pos =1;
        for(ll j=0; j<q; j++)
        {
            if(v[i][j] == '#') pos = 0;
        }
        if(pos) mp[i]++;
    }


    for(ll i=0; i<q; i++)
    {
        int pos =1;
        for(ll j=0; j<p; j++)
        {
            if(v[j][i]=='#') pos = 0;
        }
        if(pos) mpt[i]++;
    }


    for(ll i=0; i<p; i++)
    {
        int pos=0;
        for(ll j=0; j<q; j++)
        {
            if(mp[i]==0 and mpt[j]==0)
            {
                cout<<v[i][j];
                pos = 1;
            }

        }
        if(pos) cout<<endl;
    }
}
