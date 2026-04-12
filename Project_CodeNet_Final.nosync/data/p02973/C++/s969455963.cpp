#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct sir
{
    int val,poz;
};
sir a[100001];
int n,arb[1<<19],pozitie,valoare,start,finish,maxim,l,d[100001],r[100001],nr;
bool cmp(sir a, sir b)
{
    if(a.val==b.val)
    {
        return a.poz<b.poz;
    }
    else
    {
        return a.val>b.val;
    }
}
void actualizare(int nod,int st,int dr)
{
    int mij;
    if(st==dr)
    {
        arb[nod]=valoare;
        return;
    }
    mij=(st+dr)/2;
    if(pozitie<=mij)
    {
        actualizare(2*nod,st,mij);
    }
    else
    {
        actualizare(2*nod+1,mij+1,dr);
    }
    arb[nod]=max(arb[2*nod],arb[2*nod+1]);
}
void interogare(int nod,int st,int dr)
{
    int mij;
    if(start<=st && dr<=finish)
    {
        if(arb[nod]>maxim)
        {
            maxim=arb[nod];
        }
        return;
    }
    mij=(st+dr)/2;
    if(start<=mij)
    {
        interogare(2*nod,st,mij);
    }
    if(mij<finish)
    {
        interogare(2*nod+1,mij+1,dr);
    }
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].poz=i;
    }
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        if(a[i].poz-1>=1)
        {
            maxim=0;
            start=1;
            finish=a[i].poz;
            interogare(1,1,n);
            d[i]=maxim+1;
            pozitie=a[i].poz;
            valoare=d[i];
            actualizare(1,1,n);
            if(d[i]>l)
            {
                l=d[i];
            }
        }
        else
        {
            d[i]=1;
            pozitie=a[i].poz;
            valoare=d[i];
            actualizare(1,1,n);
        }
    }
    cout << l << '\n';
    return 0;
}