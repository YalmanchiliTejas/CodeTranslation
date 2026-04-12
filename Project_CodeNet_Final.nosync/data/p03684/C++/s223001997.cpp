#include <bits/stdc++.h>

using namespace std;
typedef tuple<long long,long long,long long> iii;
vector<iii> vivukhue;
long long up[100005];

long long Find(long long x)
{
    if(!up[x])
        return x;
    else
    {
        long long root = Find(up[x]);
        up[x] = root;
        return root;
    }
}

void Union_set(long long x,long long y)
{
    long long rootx = Find(x);
    long long rooty = Find(y);

    up[rootx] = rooty;
}

long long MST()
{
    long long x,y,cost,minicost=0;
    for(long long i=0;i<vivukhue.size();i++)
    {
        tie(cost,x,y) = vivukhue[i];
        if(Find(x)!=Find(y))
        {
            minicost += cost;
            Union_set(x,y);
        }
    }

    return minicost;
}

signed main()
{
    long long n;
    cin>>n;

    iii a[n+1];
    iii b[n+1];
    for(long long i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        a[i] = make_tuple(x,y,i);
        b[i] = make_tuple(y,x,i);
    }

    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++)
        vivukhue.push_back(make_tuple(get<0>(a[i])-get<0>(a[i-1]),get<2>(a[i-1]),get<2>(a[i])));

    sort(b+1,b+n+1);
    for(long long i=2;i<=n;i++)
        vivukhue.push_back(make_tuple(get<0>(b[i])-get<0>(b[i-1]),get<2>(b[i-1]),get<2>(b[i])));

    sort(vivukhue.begin(),vivukhue.end());
    for(long long i=0;i<vivukhue.size();i++)
    {
        long long cost,x,y;
        tie(cost,x,y) = vivukhue[i];
        //cout<<x<<" "<<y<<" "<<cost<<'\n';
    }
    long long miniumcost = MST();
    cout<<miniumcost;
}
