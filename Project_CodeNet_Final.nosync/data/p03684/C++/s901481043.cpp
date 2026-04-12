#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define lo long long
#define pii pair<lo,lo>
#define piii pair<pii,lo>
#define fi first
#define se second
#define mp make_pair
#define pia pair<int,pii>
#define pb push_back
using namespace std;

vector <pia> lis;
int n;
piii ko[100010];
int par[100010];
bool cmp(piii aa,piii bb)
{
    return aa.fi.se<bb.fi.se;
}
int findPar(int a)
{
    if (par[a]==a) return a;
    par[a]=findPar(par[a]);
    return par[a];
}
void Union (int a,int b)
{
    a=findPar(a);
    b=findPar(b);

    par[a]=b;
}
int main()
{
    //ifstream cin("input.in");
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>ko[i].fi.fi>>ko[i].fi.se;
        ko[i].se=i;
    }

    sort(ko,ko+n);

    for (int i=1;i<n;i++)
    {
        pia aaa=mp((ko[i].fi.fi-ko[i-1].fi.fi),mp(ko[i].se,ko[i-1].se));
        lis.pb(aaa);
    }
    sort(ko,ko+n,cmp);
    for (int i=1;i<n;i++)
    {
        pia aaa=mp((ko[i].fi.se-ko[i-1].fi.se),mp(ko[i].se,ko[i-1].se));
        lis.pb(aaa);
    }

    sort(lis.begin(),lis.end());

    for (int i=0;i<n+5;i++)
    {
        par[i]=i;
    }
    lo ans=0;
    for (int i=0;i<lis.size();i++)
    {
        if (findPar(lis[i].se.fi)==findPar(lis[i].se.se)) continue;
        ans+=lis[i].fi;
        Union(lis[i].se.fi,lis[i].se.se);
    }

    cout<<ans<<endl;
    return 0;
}
