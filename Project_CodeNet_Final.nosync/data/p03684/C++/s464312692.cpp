#include<bits/stdc++.h>
#define int long long
using namespace std;
 

bool comp1(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
    return a.first.first<b.first.first;
}
bool comp2(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
    return a.first.second<b.first.second;
}

int parent[100005];
int sz[100005];
int find_parent(int ver)
{
    if(ver==parent[ver])
        return ver;
    return parent[ver]=find_parent(parent[ver]);
}

bool merge(int a,int b)
{
    a=find_parent(a);
    b=find_parent(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
            swap(a,b);
        sz[a]+=sz[b];
        parent[b]=a;
        return true;
    }
    return false;
}

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif    

    int n;
    cin>>n;
    vector<pair<pair<int,int> ,int> >pp;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        pp.push_back({{x,y},i});
    }
    sort(pp.begin(),pp.end(),comp1);
    vector<pair<int,pair<int,int> > >lol;
    for(int i=0;i<n-1;i++)
    {
        lol.push_back({abs(pp[i].first.first-pp[i+1].first.first),{pp[i].second,pp[i+1].second}});
    }
    sort(pp.begin(),pp.end(),comp2);
    for(int i=0;i<n-1;i++)
    {
        lol.push_back({abs(pp[i].first.second-pp[i+1].first.second),{pp[i].second,pp[i+1].second}});
    }
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
    int ans=0;
    sort(lol.begin(),lol.end());
    for(auto i:lol)
    {
        if(merge(i.second.first,i.second.second))
            ans+=i.first;
    }
    cout<<ans;

}