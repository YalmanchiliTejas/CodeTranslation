#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int seg[800005];
int deg[200005];
pair<int,int>p[200005];

void build(int ver,int tl,int tr)
{
    if(tl>tr)
            return ;
    else if(tl==tr)
        seg[ver]=min(p[tl].first,p[tl].second);
    else
    {
        int tm=(tl+tr)/2;
        build(2*ver,tl,tm);
        build(2*ver+1,tm+1,tr);
        seg[ver]=max(seg[2*ver],seg[2*ver+1]);
    }
}

void upd(int ver,int tl,int tr,int pos,int val)
{
    if(tl>tr)
            return;
    else if(tl==tr)
            seg[ver]=val;
    else
    {
        int tm=(tl+tr)/2;
        if(tm>=pos)
            upd(2*ver,tl,tm,pos,val);
        else
            upd(2*ver+1,tm+1,tr,pos,val);
        seg[ver]=max(seg[2*ver],seg[2*ver+1]);
    }
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
    int mmx=0,mmn=1e18;
    for(int i=1;i<=n;i++)
    {        
        cin>>p[i].first>>p[i].second;
        mmx=max(mmx,p[i].first);
        mmn=min(mmn,p[i].first);
        mmx=max(mmx,p[i].second);
        mmn=min(mmn,p[i].second);
    }
    int mn=5e18;
    int min_ans=1e18;
    int max_ans=0;
    vector<int>temp;
    multiset<pair<int,int> >s;
    for(int i=1;i<=n;i++)
    {
        temp.push_back(p[i].first);
        temp.push_back(p[i].second);
        s.insert({p[i].first,i});
        s.insert({p[i].second,i});
    }
    sort(temp.begin(),temp.end());
    build(1,1,n);
    bool flag=true;
    for(auto i:temp)
    {
        auto j=s.lower_bound({i,-1});
        vector<pair<int,int>> madar;
        if(j!=s.begin())
        {
            j--;
            while(1)
            {
                madar.push_back(*j);
                deg[j->second]++;
                if(deg[j->second]==1)
                {
                    upd(1,1,n,j->second,max(p[j->second].first,p[j->second].second));
                }
                else
                {
                    flag=false;
                    break;
                }
                if(j==s.begin())
                {
                    break;
                }
                j--;
            }
        }        
        for(auto j:madar)
            s.erase(s.find(j));
        if(!flag)
            break;
        mn=min(mn,seg[1]-i);
    }

    if(mn!=5e18)
        mn=mn*(mmx-mmn);
    for(int i=1;i<=n;i++)
    {
        int x=p[i].first;
        int y=p[i].second;
        max_ans=max(max_ans,min(x,y));            
        min_ans=min(min_ans,max(x,y));
    }
    mn=min(mn,(mmx-min_ans)*(max_ans-mmn));
    cout<<mn;
} 
