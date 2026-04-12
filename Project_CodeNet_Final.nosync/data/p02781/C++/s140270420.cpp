#include<bits/stdc++.h>
using namespace std;
string s,p;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t,i,j,n,m,l,r,k,c,ans=0;
    cin>>s>>c;
    n=s.size();
    for(i=0; i<n; i++)
    {
        p+='0';
    }
    if(c==1)
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
    else if(c==2)
    {
        m=n-2;
        ans+=81*((m*(m+1))/2);
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
        m=n-3;
        l=0,r=1;
        while(m>0)
        {
            l+=(m*r);
            m--,r++;
        }
        ans+=729*l;
        for(i=1; i<10; i++)
        {
            p[0]=(char)(i+48);
            for(j=1; j<10; j++)
            {
                for(k=1; k<n-1; k++)
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