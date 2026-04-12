#include<bits/stdc++.h>
#define ll long long
#define MAX_N 1000000039
using namespace std;
struct card
{
    ll lw,rw;
};
card num[200039];
ll lmax=-1,rmax=-1,lmin=MAX_N,rmin=MAX_N,rankmax,rankmin,smax,smin=MAX_N,stpmin=MAX_N;
bool cmp(card a,card b)
{
    return a.rw<b.rw;
}
void exc(int k)
{
    int stp;
    stp=num[k].rw;
    num[k].rw=num[k].lw;
    num[k].lw=stp;
}
int main()
{
    ll ans,stp,stpans,n,a,b,c;
    scanf("%lld",&n);
    for(a=1;a<=n;a++)
    {
        scanf("%lld%lld",&b,&c);
        num[a].lw=max(b,c);
        num[a].rw=min(b,c);
        if(num[a].lw>=lmax)
        {
            lmax=num[a].lw;
            rankmax=a;
        }
        if(num[a].rw<=rmin)
        {
            rmin=num[a].rw;
            rankmin=a;
        }
        lmin=min(lmin,num[a].lw);
        rmax=max(rmax,num[a].rw);
    }
    ans=(lmax-lmin)*(rmax-rmin);
    stp=lmax-rmin;
    if(rankmax!=rankmin)
    {
        sort(num+1,num+1+n,cmp);
        for(a=1;a<=n;a++)
        {
            if(num[a].lw==lmax)
            {
                rankmax=a;
                break;
            }
        }
        exc(1);
        if(num[1].rw<=num[2].rw)
        {
            smin=num[1].rw;
            rankmin=1;
        }
        else   
        {
            smin=num[2].rw;
            rankmin=2;
        }
        smax=max(num[1].rw,num[n].rw);
        ans=min(ans,stp*(smax-smin));
        for(a=2;a<=n;a++)
        {
            if(a!=rankmax)
            {
                exc(a);
            }
            if(a==rankmin)
            {
                if(num[a].rw>num[a+1].rw)
                {
                    smin=num[a+1].rw;
                    rankmin=a+1;
                }
                else
                {
                    smin=num[a].rw;
                    rankmin=a;
                }
            }
            stpmin=min(stpmin,num[a-1].rw);
            if(stpmin<=smin)
            {
                smin=stpmin;
                rankmin=1;
            }
            smax=max(smax,num[a].rw);
            ans=min(ans,stp*(smax-smin));
        }
    }
    printf("%lld",ans);
    return 0;
}