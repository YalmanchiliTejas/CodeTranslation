#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ar array
#define db double
#define filename "SUBKGCD"
#define pow pw
const db pi = 3.14159265358979323846;
int pw(int a,int b){
	int ans=1;
	while(b){
	if (b%2) ans*=a;
	a*=a;
	b/=2;
	}
	return(ans);
}
const int mxn=2e5+3,INF=1e18;
int n,q;
struct BST
{
    int mx;
} st[4*mxn];
void upd(int i,int v,int x=1,int l2=0,int r2=n-1)
{
    if (l2==r2)
    {
        st[x].mx=v;
        return;
    }
    int m=(l2+r2)/2;
    if (i<=m) upd(i,v,2*x,l2,m);
    else upd(i,v,2*x+1,m+1,r2);
    st[x].mx=max(st[2*x].mx,st[2*x+1].mx);
}
int que(int l,int r,int x=1,int l2=0,int r2=n-1)
{
    if (r2<l||l2>r) return(-INF);
    if (l<=l2&&r2<=r) return(st[x].mx);
    int m=(l2+r2)/2;
    return(max(que(l,r,2*x,l2,m),que(l,r,2*x+1,m+1,r2)));
}
int que2(int k,int l,int x=1,int l2=0,int r2=n-1)
{
    if (st[x].mx<k) return(n);
    if (r2<l) return(n);
    if (l2==r2) return(l2);
    int m=(l2+r2)/2;
    int res=que2(k,l,2*x,l2,m);
    if (res==n) res=que2(k,l,2*x+1,m+1,r2);
    return(res);
}
signed main()
{
    //freopen(filename".inp","r",stdin);
    //freopen(filename".out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        upd(i,x);
    }
    while(q--)
    {
        int qu,a,b;
        cin>>qu>>a>>b;
        if (qu==1)
        {
            upd(a-1,b);
        }
        else if (qu==2)
        {
            cout<<que(a-1,b-1)<<"\n";
        }
        else
        {
            cout<<que2(b,a-1)+1<<"\n";
        }
    }
	return 0;
}
