#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int un[101000];
int get(int i)
{
    if (un[i] == i)
        return i;
    return un[i] = get(un[i]);
}

void mrg(int i, int j)
{
    un[get(i)] = get(j);
}

int n;
int x[100100];
int y[100100];
vector<pair<int,int>> xs, ys;

vector<pair<int,pair<int,int>>> e;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        xs.push_back({x[i],i});
        ys.push_back({y[i],i});
        un[i] = i;
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    for(int i = 0; i < n-1; i++)
        e.push_back({xs[i+1].first-xs[i].first,{xs[i+1].second,xs[i].second}});
    for(int i = 0; i < n-1; i++)
        e.push_back({ys[i+1].first-ys[i].first,{ys[i+1].second,ys[i].second}});
    sort(e.begin(),e.end());
    long long sum = 0;
    for(auto w : e)
    {
        int u = w.second.first;
        int v = w.second.second;
        int c = w.first;
        if (get(u) == get(v))
            continue;
        mrg(u,v);
        sum += c;
    }
    printf("%lld\n",sum);
    return 0;
}
