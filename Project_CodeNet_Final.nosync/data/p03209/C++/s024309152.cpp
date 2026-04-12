#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=55;

ll len[N];
ll cate[N];

inline ll ask(ll l,ll p)
{
    if(l==0)
    {
        if(p==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(p==1)
        {
            return 0;
        }
        if(p<=len[l-1]+1)
        {
            return ask(l-1,p-1);
        }
        if(p==len[l-1]+2)
        {
            return cate[l-1]+1;
        }
        if(p<=2*len[l-1]+2)
        {
            return cate[l-1]+1+ask(l-1,p-(len[l-1]+2));
        }
        if(p==2*len[l-1]+3)
        {
            return 2*cate[l-1]+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    len[0]=1;
    cate[0]=1;
    for(int i=1;i<N;i++)
    {
        len[i]=2*len[i-1]+3;
        cate[i]=2*cate[i-1]+1;
    }
    ll n,p;
    cin>>n>>p;
    cout<<ask(n,p)<<"\n";
    return 0;
}
