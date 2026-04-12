#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct interval{
    ll score;
int open,close;
};
class segtree{
    ll *tree;
    ll *upd;
    int n;
    public:
    segtree(int n)
    {
        this->n = n;
        tree = new ll[4*n]{0};
        upd = new ll[4*n]{0};
    }
    void push(int node)
    {
        tree[2*node+1] += upd[node];
        tree[2*node+2] += upd[node];
        upd[2*node+1] += upd[node];
        upd[2*node+2] += upd[node];
        upd[node] = 0;
    }
    void update(int idx,int s,int e,int l,int r,ll val)
    {
        if(l>e||r<s)
        return;
        if(s>=l&&e<=r)
        {
            tree[idx] += val;
            upd[idx] += val;
            return;
        }
        int mid = (s+e)/2;
        push(idx);
        update(2*idx+1,s,mid,l,r,val);
        update(2*idx+2,mid+1,e,l,r,val);
        tree[idx] =  max(tree[2*idx+1],tree[2*idx+2]);
    }
    ll query(int idx,int s,int e,int l,int r)
    {
        if(l>e||r<s)
        return LONG_MIN;
        if(s>=l&&e<=r)
        {
            return tree[idx];
        }
        int mid = (s+e)/2;
        push(idx);
        ll a = query(2*idx+1,s,mid,l,r);
        ll b = query(2*idx+2,mid+1,e,l,r);
        return max(a,b);
    }
};
ll solve(vector<interval> v,int n)
{
    vector<int> endings[n];
    for(int i=0;i<v.size();i++)
    {
        endings[v[i].close].push_back(i);
    }
    segtree dp(n);
    for(auto j:endings[0])
    {
        dp.update(0,0,n-1,v[j].open,v[j].close,v[j].score);
    }
    for(int i=1;i<n;i++)
    {
        ll large = max(dp.query(0,0,n-1,0,i-1),0ll);
        // cout<<i<<" "<<large<<endl;
        dp.update(0,0,n-1,i,i,large);
        for(auto j:endings[i])
        {
            dp.update(0,0,n-1,v[j].open,v[j].close,v[j].score);
        }
    }

    return max(dp.query(0,0,n-1,0,n-1),0ll);
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<interval> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i].open>>v[i].close>>v[i].score;
        v[i].open--;
        v[i].close--;
    }
    cout<<solve(v,n);
}
