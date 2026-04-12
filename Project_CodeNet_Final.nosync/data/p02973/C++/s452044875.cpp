#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
int dp[1000000];
int tree[4000000];
int query(int x,int l,int r,int s,int e){
    if (s>r || e<l)return 0;
    if (l>=s && r<=e)return tree[x];
    return max(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
}
void upd(int x,int l,int r,int v,int val){
    if (v>r || v<l)return;
    if (l==r)tree[x]=val;
    else {
        upd(L,l,mid,v,val);
        upd(R,mid+1,r,v,val);
        tree[x]=max(tree[R],tree[L]);
    }
}
map<int,int> mp;
set<int> s;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i], s.insert(a[i]);
    int cur=1;
    for (auto x:s){
        mp[x]=cur++;
    }
    int ret=0;
    for (int i=1;i<=n;i++) {
        a[i]=mp[a[i]];
        dp[i]=query(1,0,cur,a[i],cur)+1;
        upd(1,0,cur,a[i],dp[i]);
        ret=max(ret,dp[i]);
    }
    cout<<ret<<endl;
}