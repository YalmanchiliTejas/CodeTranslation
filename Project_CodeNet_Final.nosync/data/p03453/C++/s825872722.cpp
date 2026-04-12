#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e5+5; 
const int  maxn=5e5+5;
int n,m,tot;
ll  head[maxn],ver[maxn],edge[maxn],Next[maxn],d[maxn];
ll dis[2][maxn],ans[2][maxn];
bool v[2][maxn];
int const mod=1e9+7;
int s,t;


void add(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
void dijk(int l,ll d[],bool v[],ll a[]){
	priority_queue< pair<ll,int> >q;
	d[l]=0;
	a[l]=1;
	q.push(make_pair(0,l));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(v[x])
		continue;
		v[x]=1;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				a[y]=a[x];
				
				q.push(make_pair(-d[y],y));
			}
			else if(d[y]==d[x]+z) 
			{  a[y]=(a[x]+a[y])%mod;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	cin>>s>>t;
	tot=0;
	memset(head,-1,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	} 
	dijk(s,dis[0],v[0],ans[0]);	
	dijk(t,dis[1],v[1],ans[1]);
//	cout<<ans[0][t]<<endl;
	ll num=((ans[0][t]%mod)*(ans[1][s]%mod))%mod;
//	cout<<num<<endl; 
	ll L=dis[0][t];
//	cout<<L<<endl; 
	for(int i=1;i<=n;i++){
		if(dis[0][i]==dis[1][i]&&L==dis[0][i]*2){
//			cout<<i<<endl;
			num=num-((ans[0][i]*ans[0][i]%mod)*(ans[1][i]*ans[1][i]%mod))%mod;
			num=(num+mod)%mod;
//				cout<<num<<endl; 
		}
		for(int j=head[i];~j;j=Next[j]){
				int y=ver[j],z=edge[j];
				ll l1=dis[0][i],l2=dis[1][y];
//				cout<<l1<<" "<<z<<" "<<l2<<endl;
				if(l1+z+l2==L&&l1*2<L&&l2*2<L){
					num=num-((ans[0][i]*ans[0][i]%mod)*(ans[1][y]*ans[1][y]%mod))%mod;
			num=(num+mod)%mod;
//				cout<<num<<endl; 
				}
		}
	}
	cout<<num<<endl;
}