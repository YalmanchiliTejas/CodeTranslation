#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;

int n,ans,cnt;
int x[100005];
int y[100005];
int par[100005];
pair<int,int> f[200005];
pair<int,int> nei[200005];
pair<int,int> val[200005];

int getPar(int x){
	if(x==par[x]) return x;
	return par[x]=getPar(par[x]);
}

int Ab(int x){
	if(x<0) return -x;
	return x;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) par[i]=i;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++) f[i]=make_pair(x[i],i);
	sort(f,f+n);
	for(int i=0;i<n-1;i++){
		int l=f[i].second;
		int r=f[i+1].second;
		nei[cnt]=make_pair(l,r);
		val[cnt]=make_pair(min(Ab(y[l]-y[r]),Ab(x[l]-x[r])),cnt);
		cnt++;
	}
	for(int i=0;i<n;i++) f[i]=make_pair(y[i],i);
	sort(f,f+n);
	for(int i=0;i<n-1;i++){
		int l=f[i].second;
		int r=f[i+1].second;
		nei[cnt]=make_pair(l,r);
		val[cnt]=make_pair(min(Ab(y[l]-y[r]),Ab(x[l]-x[r])),cnt);
		cnt++;
	}
	sort(val,val+cnt);
	int tot=0;
	for(int i=0;i<cnt,tot<n-1;i++){
		int now=val[i].second;
		int l=nei[now].first;
		int r=nei[now].second;
		l=getPar(l);
		r=getPar(r);
		if(l!=r){
			par[l]=r;
			tot++;
			ans+=val[i].first;
		}
	}
	cout<<ans<<endl;
	return 0;
}