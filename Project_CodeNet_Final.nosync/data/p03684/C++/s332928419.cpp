#include<map>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#define mp make_pair
using namespace std;
int in[100005][2];
int u[100005];
int r[100005];
inline int root(int x){
	if(x==r[x]) return x;
	else return r[x]=root(r[x]);
}
vector<pair<long long,pair<int,int> > >v;
inline bool cmp1(int x,int y){return in[x][0]<in[y][0];}
inline bool cmp2(int x,int y){return in[x][1]<in[y][1];}
int main(){
	int n,i,x,y;
	cin>>n;
	for(i=0;i<n;i++) cin>>in[i][0]>>in[i][1];
	for(i=0;i<n;i++) u[i]=r[i]=i;
	sort(u,u+n,cmp1);
	for(i=0;i<n-1;i++) v.push_back(mp(in[u[i+1]][0]-in[u[i]][0],mp(u[i],u[i+1])));
	sort(u,u+n,cmp2);
	for(i=0;i<n-1;i++) v.push_back(mp(in[u[i+1]][1]-in[u[i]][1],mp(u[i],u[i+1])));
	sort(v.begin(),v.end());
	long long ans=0;
	for(i=0;i<v.size();i++){
		pair<long long,pair<int,int> > it;
		it=v[i];
		if(root(it.second.first)==root(it.second.second)) continue;
		ans+=it.first;
		r[root(it.second.first)]=root(it.second.second);
	}
	cout<<ans<<endl;
	return 0;
}