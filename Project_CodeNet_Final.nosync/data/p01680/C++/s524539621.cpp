#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}

ll pow(ll a,ll b){
  if(b==0)return 1;
  else if(b%2==0)return pow(a*a%mod,b/2);
  else return pow(a*a%mod,b/2)*a%mod;
}



#define MAX 100005
int pa[MAX];
int ra[MAX];
void init(){
  for(int i=0;i<MAX;i++){
    pa[i]=i;
    ra[i]=0;
  }
}

int find(int x){
  if(pa[x]==x)return x;
  else return pa[x]=find(pa[x]);
}

void unite(int x,int y){
  x=find(x),y=find(y);
  if(x==y)return;
  if(ra[x]<ra[y])swap(x,y);
  pa[y]=x;
  if(ra[x]==ra[y])ra[x]++;
}

bool same(int x,int y){
  return (find(x)==find(y));
}

int n,m,a,b;

int main(){
  while(1){
    cin>>n>>m;
    if(n==0&&m==0)break;
    init();
    for(int i=0;i<m;i++){
      scanf("%d %d",&a,&b);
      unite(a,b);
    }
    ll cnt=0;
    for(int i=1;i<=n;i++)
      if(find(i)==i)
        cnt++;
    
    cout<<add(pow(2LL,cnt),(cnt==n?0:1))<<endl;
  }
  return 0;
}