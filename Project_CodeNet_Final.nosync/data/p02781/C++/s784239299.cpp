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
//vector<int>v;
//map<int,int>mp;

int main()
{
    ft
    ll t,i,j,n,m,l,r,ans=0;
    cin>>s>>m;
    if(m==1)
    {
        n=s.size();
        ans+=(9*(n-1));
        int f=0;
        for(i=0; i<n; i++)
        {
            if(s[i]!='0')
            {
                f++;
            }
        }
        ans+=(s[0]-48);
    }
    else if(m==2)
    {
        n=s.size();
        m=n-2;
        ans+=81*((m*(m+1))/2);
        p="";
        for(i=0; i<n; i++)
        {
            p+="0";
        }
        for(i=1; i<10; i++)
        {
            p[0]=(char)(i+48);
            for(j=1; j<10; j++)
            {
                for(int k=1; k<n; k++)
                {
                    p[k]=(char)(j+48);
                    if(p<=s)
                    {
                        ans++;
                    }
                    p[k]='0';
                }
            }
        }
    }
    else
    {
        n=s.size();
        m=n-3;
        l=0,r=1;
        while(m>0)
        {
            l+=(m*r);
            m--,r++;
        }
        ans+=729*l;
        p="";
        for(i=0; i<n; i++)
        {
            p+="0";
        }
        for(i=1; i<10; i++)
        {
            p[0]=(char)(i+48);
            for(j=1; j<10; j++)
            {
                for(int k=1; k<n-1; k++)
                {
                    p[k]=(char)(j+48);
                    for(r=1; r<10; r++)
                    {
                        for(l=k+1; l<n; l++)
                        {
                            p[l]=(char)(r+48);
                            if(p<=s)
                            {
                                ans++;
                            }
                            p[l]='0';
                        }
                    }
                    p[k]='0';
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
