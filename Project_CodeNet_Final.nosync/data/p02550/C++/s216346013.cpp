#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    LL n,x,m;
    cin>>n>>x>>m;
    vector<int>pos(m+1,-1);
    vector<LL>rest(m+1);
    int nr=1;
    pos[x]=0;
    rest[0]=x;
    x=(x*x)%m;
    while(pos[x]==-1)
        rest[nr]=x,
        pos[x]=nr,
        ++nr,
        x=(x*x)%m;
    LL serie=0;
    int start=pos[x];
    for (int i=start;i<nr;++i)
        serie+=rest[i];
    LL s=0;
    for (int i=0;i<n && i<start;++i)
        s+=rest[i];
    if (n<=start)
    {
        cout<<s;
        return 0;
    }
    n-=start;
    nr-=start;
    LL nrserii=n/nr;
    LL ramase=n%nr;
    s=s+nrserii*serie;
    for (int i=0;i<ramase;++i)
        s=s+rest[start+i];
    cout<<s;
}

