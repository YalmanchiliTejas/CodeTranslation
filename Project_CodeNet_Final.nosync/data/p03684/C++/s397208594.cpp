#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int p[N] , w[N];
int n;
int f(int u){
    if(u == p[u])return u;
    return p[u] = f(p[u]);
}
void connect(int a , int b){
    a = f(a);
    b = f(b);
    if(a == b)return;
    if(w[a] < w[b])swap(a,b);
    w[a] += w[b];
    p[b] = a;
}

void init(){
    for(int i = 0 ; i < N ; i++)
        p[i] = i , w[i] = 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    init();
    vector< pair<int,int> >vx,vy;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vx.push_back({x,i});
        vy.push_back({y,i});
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    vector<pair< int , pair<int,int> > >v;
    for(int i=1;i<vx.size();i++)
        v.push_back({vx[i].first-vx[i-1].first,{vx[i].second,vx[i-1].second}});

    for(int i=1;i<vy.size();i++)
        v.push_back({vy[i].first-vy[i-1].first,{vy[i].second,vy[i-1].second}});
    sort(v.begin(),v.end());
    long long ans=0;
    for(int i=0;i<v.size();i++)
    {
        int a=v[i].second.first,b=v[i].second.second;
        if(f(a)==f(b)) continue;
        connect(a,b);
        ans+=v[i].first;
    }
    cout<<ans<<endl;
    return 0;
}
