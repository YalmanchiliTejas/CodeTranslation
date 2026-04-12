    #include<bits/stdc++.h>
    using namespace std;
    vector<pair<int,int> > add[2000000];
    vector<pair<int,int> > rem[2000000];
     
    long long dp[2000000];
    long long tree[2000000];
    long long lazy[2000000];
    void lzy(int x)
    {
        tree[x]+=lazy[x];
        lazy[x*2]+=lazy[x];
        lazy[x*2+1]+=lazy[x];
        lazy[x]=0;
    }
    void update(int x,int l,int r,int s,int e,long long v)
    {
        lzy(x);
        if (s>r || e<l)return;
        if (l>=s && r<=e)
        {
            lazy[x]=v;
            lzy(x);
            return;
        }
        update(x*2,l,(l+r)/2,s,e,v);
        update(x*2+1,(l+r)/2+1,r,s,e,v);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
    long long query(int x,int l,int r,int s,int e)
    {
        lzy(x);
        if (l>e || r<s)return -1e16;
        if (l>=s && r<=e)return tree[x];
        return max(query(x*2,l,(l+r)/2,s,e),query(x*2+1,(l+r)/2+1,r,s,e));
    }
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int n,m;
        cin>>n>>m;
        for (int i=0;i<m;i++)
        {
            int l,r,v;
            cin>>l>>r>>v;
            add[l].push_back({l-1,v});
            rem[r].push_back({l-1,-v});
        }
        for (int i=1;i<=n;i++)
        {
            for (auto x:add[i])update(1,0,n,0,x.first,x.second);
            dp[i] = query(1,0,n,0,i-1);
            for (auto x:rem[i])update(1,0,n,0,x.first,x.second);
            update(1,0,n,i,i,dp[i]);
        }
        cout<<*(max_element(dp,dp+n+1))<<endl;
    }