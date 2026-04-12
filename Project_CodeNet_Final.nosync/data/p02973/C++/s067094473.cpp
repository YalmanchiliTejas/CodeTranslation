#include <bits/stdc++.h>

using namespace std;

vector<int> tree(4*100005,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[n-i].first);
        v[n-i].second=i;
    }
    stable_sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){return a.first<b.first;});
    int res=0;
    for(pair<int,int> p:v)
    {
        int pos=p.second;
        int id=query(1,1,n,1,pos);
        if(id==0) res++;
        else update(1,1,n,id,0);
        update(1,1,n,pos,pos);
    }
    printf("%d\n",res);
    return 0;
}
