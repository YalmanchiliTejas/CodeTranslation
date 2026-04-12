    #include <bits/stdc++.h>
    using namespace std;
    int n,m;
    const long long inf=1000000000000000;
    const int N=200009;
    vector<int>vv[N],v[N];
    pair<int,int>a[N];
    long long laz[4*N*2];
    long long  tree[4*N*2];
    void up(int ind,int st,int end ,int l,int r,long long val)
    {
        if (laz[ind]!=0)
        {
            tree[ind]+=laz[ind];
            if (st!=end){laz[ind*2+1]+=laz[ind];
            laz[ind*2+2]+=laz[ind];}
            laz[ind]=0;
        }
        if (l<=st&&end<=r)
        {
            tree[ind]+=val;
            if (st!=end){laz[ind*2+1]+=val;
            laz[ind*2+2]+=val;}
            return ;
        }
        if (r<st||l>end)return ;
        int m=(st+end )/2;
        up(ind*2+1, st,m , l, r, val);
        up(ind*2+2, m+1,end , l, r, val);
        tree[ind]=max(tree[ind*2+1],tree[ind*2+2]);
    }

    long long query(int ind,int st,int end ,int l,int r)
    {
    //    cout<<st<<" "<<end<<endl;
        if (laz[ind]!=0)
        {
            tree[ind]+=laz[ind];
            if (st!=end){laz[ind*2+1]+=laz[ind];
            laz[ind*2+2]+=laz[ind];}
            laz[ind]=0;
        }
        if (l<=st&&end<=r)
        {return tree[ind];
        }
        if (r<st||l>end)return -inf;
        int m=(st+end )/2;
        return max(query(ind*2+1, st,m , l, r),query(ind*2+2, m+1,end , l, r));
        }
    int main()
    {
        int x,y,z;
        cin>>n>>m;
        for(int i=1;i<m+1;i++)
        {
            cin>>x>>y>>z;
            a[i]=make_pair(x,z);
            v[x].push_back(i);
            vv[y].push_back(i);
        }
        //for(int i=0;i<N*8+12;i++)tree[i]=-inf;
        for(int i=1;i<n+1;i+=1)
        {

            for(auto it:v[i])
            {
                //cout<<a[it].second<<endl;
                up(0,0,n,0,i-1,a[it].second);
            }
            long long x=query(0,0,n,0,i-1);
            up(0,0,n,i,i,x);
            for(auto it:vv[i])
            {
                up(0,0,n,0,a[it].first-1,-a[it].second);
            }
        }
        long long u=0;
        cout<<max(query(0,0,n,0,n),u);
    }
