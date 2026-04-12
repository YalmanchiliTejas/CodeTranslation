#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
long long mod=1000000007;
int g[110][110];
pair<int,pair<int,int> > edge[11000];
int UF[110];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int conv[110];
int ind[110];
vector<int>v[10];
long long getinv(long long a){
	long long ret=1;
	int t=mod-2;
	while(t){
		if(t%2)ret=ret*a%mod;
		a=a*a%mod;
		t/=2;
	}
	return ret;
}
long long mat[110][110];
long long calc(vector<int>p){
	int n=p.size();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)mat[i][j]=0;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		if(g[p[i]][p[j]]){
			mat[i][j]=mat[j][i]=mod-1;
			mat[i][i]++;
			mat[j][j]++;
		}
	}
	//for(int i=0;i<n-1;i++){
	//	for(int j=0;j<n-1;j++)printf("%lld ",mat[i][j]);
	//	printf("\n");
	//}
	long long ret=1;
	for(int i=0;i<n-1;i++){
		int at=-1;
		for(int j=i;j<n-1;j++){
			if(mat[j][i]){
				at=j;break;
			}
		}
		if(!~at)return 0;
		if(at!=i)ret=(mod-ret)%mod;
		for(int j=0;j<n-1;j++)swap(mat[at][j],mat[i][j]);
		ret=ret*mat[i][i]%mod;
		long long ks=getinv(mat[i][i]);
		for(int j=0;j<n-1;j++)mat[i][j]=mat[i][j]*ks%mod;
		for(int j=i+1;j<n-1;j++){
			long long tmp=mat[j][i];
			for(int k=0;k<n-1;k++)mat[j][k]=(mat[j][k]+mod-tmp*mat[i][k]%mod)%mod;
		}
	}
	return ret;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		p--;q--;
		g[p][q]=g[q][p]=1;
		edge[i]=make_pair(r,make_pair(p,q));
	}
	std::sort(edge,edge+b);
	for(int i=0;i<a;i++)UF[i]=-1;
	int dist=0;
	for(int i=0;i<b;i++){
		UNION(edge[i].second.first,edge[i].second.second);
		if(UF[FIND(0)]==-a){
			dist=edge[i].first;break;
		}
	}
	for(int i=0;i<a;i++)UF[i]=-1;
	for(int i=0;i<b;i++){
		if(dist>edge[i].first)UNION(edge[i].second.first,edge[i].second.second);
	}
	int n=0;
	for(int i=0;i<a;i++)if(UF[i]<0)conv[i]=n++;
	for(int i=0;i<a;i++)if(UF[i]>=0)conv[i]=conv[FIND(i)];
	for(int i=0;i<a;i++){
		ind[i]=v[conv[i]].size();
		v[conv[i]].push_back(i);
	}
	//for(int i=0;i<a;i++)printf("%d\n",conv[i]);
	long long ret=0;
	for(int i=0;i<(1<<n);i++){
		if(i==0||i==(1<<n)-1)continue;
		vector<int>L;
		vector<int>R;
		for(int j=0;j<a;j++){
			if(i&(1<<(conv[j])))L.push_back(j);
			else R.push_back(j);
		}
		ret=(ret+calc(L)*calc(R))%mod;
	}
	printf("%d %lld\n",dist,ret);
}