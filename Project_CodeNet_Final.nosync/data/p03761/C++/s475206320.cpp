#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+3;
string s,p;
int main()
{
    ft
    ll t,i,j,n,m,l,r,a[27],c[27];
    for(i=0; i<26; i++)
    {
        a[i]=LLONG_MAX;
    }
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>s;
        memset(c,0,sizeof(c));
        for(char cc:s)
        {
            l=cc-97;
            c[l]++;
        }
        for(j=0; j<26; j++)
        {
            a[j]=min(a[j],c[j]);
        }
    }
    for(i=0; i<26; i++)
    {
        if(a[i]>0)
        {
            for(j=0; j<a[i]; j++)
            {
                cout<<(char)(i+97);
            }
        }
    }
    return 0;
}

