#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=2e5+5;
struct node
{
  int p,mx;
  node()
  {
    p=0;
    mx=0;
  }
}; 
node merge(node a,node b)
{
  node c;
  return c;
}
 
vector<node> bit(4*N);

void propagate(int id)
{
  bit[2*id].p+=bit[id].p;
  bit[2*id+1].p+=bit[id].p;
  bit[2*id].mx+=bit[id].p;
  bit[2*id+1].mx+=bit[id].p;
  bit[id].p=0;
} 

 
int get(int id,int l,int r,int L,int R)
{
  if(R<l||r<L){
    return INT_MIN;
  }
  if(L<=l&&r<=R)
  {
    return bit[id].mx;
  }
  propagate(id);
  int mid=(l+r)/2;
  
 int ans=max(get(2*id,l,mid,L,R),get(2*id+1,mid+1,r,L,R));
  bit[id].mx=max(bit[2*id].mx,bit[2*id+1].mx);
 return ans;
}


void upd(int id,int l,int r,int L,int R,int v)
{
  if(R<l||r<L)
    return;
  if(L<=l&&r<=R)
  {
    bit[id].p+=v;
    bit[id].mx+=v;
    return;
  }
  propagate(id);
  int mid=(l+r)/2;
  upd(2*id,l,mid,L,R,v);
  upd(2*id+1,mid+1,r,L,R,v);
  bit[id].mx=max(bit[2*id].mx,bit[2*id+1].mx);
  //bit[id]=merge(bit[2*id],bit[2*id+1]);
}
 
 

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

 
 int n,m;
 cin>>n>>m;

 int a[m+1][3];
 vector<int> v[n+1];
 for(int i=1;i<=m;i++)
 {
  cin>>a[i][0]>>a[i][1]>>a[i][2];
  v[a[i][1]].push_back(i);
 }

 for(int i=1;i<=n;i++)
 {
  int x=max(0,get(1,1,n,1,n-1));
  upd(1,1,n,i,i,x);
  for(auto j:v[i])
  {
    upd(1,1,n,a[j][0],a[j][1],a[j][2]);
  }
 }
 // for(int i=1;i<=n;i++)
 // {
 //  cout<<i<<" "<<get(1,1,n,1,i)<<endl;
 // }

 int ans=max(0,get(1,1,n,1,n));
 cout<<ans;



} 