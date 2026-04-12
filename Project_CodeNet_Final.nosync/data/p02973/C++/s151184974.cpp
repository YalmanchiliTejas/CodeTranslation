#include <bits/stdc++.h>
using namespace std;
const int nmax=3e5+3;
int v[nmax],x,k,st,dr,n,sol;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>x;
    v[++k]=x;
    for(int i=2;i<=n;++i)
    {
        cin>>x;
        if(x<=v[k])
        {
            v[++k]=x;
            continue;
        }
        st=1;
        dr=k;
        while(st<=dr)
        {
            int mij=(st+dr)/2;
            if(v[mij]<x)
            {
                sol=mij;
                dr=mij-1;
            }
            else st=mij+1;
        }
        v[sol]=x;
    }
    cout<<k;
    return 0;
}
