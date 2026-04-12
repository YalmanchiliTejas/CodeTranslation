#include <bits/stdc++.h>

using namespace std;

vector<long long>sz;
vector<long long>rep;
long long nc;

long long findu(long long u)
{
    if(u==rep[u])
    {
        return u;
    }
    return rep[u]=findu(rep[u]);
}

void join(long long a,long long b)
{
    a=findu(a);
    b=findu(b);
    if(a==b)
    {
        return;
    }
    if(sz[a]<sz[b])
    {
        swap(a,b);
    }
    sz[a]+=sz[b];
    rep[b]=a;
    nc--;
}


int main()
{
    map<pair<long long, long long>, long long> nodes;
    long long N;
    cin >> N;
    vector <pair < long long, pair<long long, long long>> > xs;
    vector <pair < long long, pair<long long, long long> > > ys;
    for(int i=0; i<N; i++)
    {
        long long x, y;
        cin >> x >> y;
        nodes[ {x,y}]=i+1;
        xs.push_back({x,{y, i + 1}});
        ys.push_back({y,{x, i+1}});
    }
    sz=vector<long long>(N+1);
    rep=vector<long long>(N+1);
    nc=N;
    for(int i=1; i<=N; i++)
    {
        rep[i]=i;
        sz[i]=1;
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    map<long long, vector < pair<long long, long long > > > costs;
    for(int i=0; i<xs.size()-1; i++)
    {
        long long x1=xs[i].first, x2=xs[i+1].first;
        long long y1=xs[i].second.first, y2=xs[i+1].second.first;
        long long id1 = xs[i].second.second, id2 = xs[i+1].second.second;
        costs[abs(x1-x2)].push_back({id1,id2});
    }
    for(int i=0; i<ys.size()-1; i++)
    {
        long long x1=ys[i].second.first, x2=ys[i+1].second.first;
        long long y1=ys[i].first, y2=ys[i+1].first;
        long long id1 = ys[i].second.second, id2 = ys[i+1].second.second;
        costs[abs(y1-y2)].push_back({id1,id2});
    }
    map<long long, vector < pair<long long, long long > > >::iterator it;
    long long res=0;
    for(it=costs.begin(); it!=costs.end(); it++)
    {
        for(int i=0; i<(it->second).size(); i++)
        {
            long long tmpa=findu((it->second)[i].first) , tmpb = findu((it->second)[i].second);
            if(tmpa!=tmpb)
            {
                join(tmpa,tmpb);
                res+=(it->first);
            }
        }
    }
    cout << res << endl;
    /*long long a , b ,w;
    for(int i=0; i<M; i++){
            cin >> a >> b >> w;
            grid[a].push_back(b);
            ce.push_back({w,{a,b}});
    }
    sort(ce.begin(),ce.end());

    long long res=0;
    for(int i=0; i<ce.size(); i++){
        long long tmpa=findu(ce[i].second.first) , tmpb = findu(ce[i].second.second);
        if(tmpa!=tmpb){
            join(ce[i].second.first,ce[i].second.second);
            res+=ce[i].first;
        }
    }
    cout << res << endl;
    */

    return 0;
}
