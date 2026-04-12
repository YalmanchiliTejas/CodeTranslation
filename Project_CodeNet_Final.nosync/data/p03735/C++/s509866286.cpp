#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define INF 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int n,n_;
vector<P> vec;
vector<ll> vec2;
struct data{
	ll val,lazy;
	data(){}
	data(ll vv,ll la){
		val=vv;
		lazy=la;
	}
};

data dat[1<<20];

void lazy_evaluate(int k){
	dat[k].val=max(dat[k].val,dat[k].lazy);
	if(k<n_-1){
		dat[k*2+1].lazy=max(dat[k].lazy,dat[k*2+1].lazy);
		dat[k*2+2].lazy=max(dat[k].lazy,dat[k*2+2].lazy);
	}
}

void lazy_update(int k){
}

void update(int a,int b,ll v,int k=0,int l=0,int r=n_){
	lazy_evaluate(k);
	if(r<=a || b<=l)return;
	if(a<=l && r<=b){
		dat[k].lazy=max(dat[k].lazy,v);
		lazy_evaluate(k);
		return;
	}
	update(a,b,v,k*2+1,l,(l+r)/2);
	update(a,b,v,k*2+2,(l+r)/2,r);
	lazy_update(k);
	return;
}

ll query(int a,int b,int k=0,int l=0,int r=n_){
	lazy_evaluate(k);
	if(r<=a || b<=l)return INF;
	if(a<=l && r<=b)return dat[k].val;
	ll vl=query(a,b,k*2+1,l,(l+r)/2);
	ll vr=query(a,b,k*2+2,(l+r)/2,r);
	lazy_update(k);
	return min(vl,vr);
}

int main(void){
	scanf("%d",&n);
	ll maxi=0,mini=INF;
	for(int i=0;i<n;i++){
		P p;
		scanf("%lld%lld",&p.first,&p.second);
		vec.push_back(p);
		if(vec[i].first>vec[i].second){
			swap(vec[i].first,vec[i].second);
		}
		maxi=max(vec[i].first,maxi);
		maxi=max(vec[i].second,maxi);
		mini=min(vec[i].first,mini);
		mini=min(vec[i].second,mini);
		vec2.push_back(vec[i].first);
		vec2.push_back(vec[i].second);
	}
	sort(vec2.begin(),vec2.end());
	vec2.erase(unique(vec2.begin(),vec2.end()),vec2.end());
	bool fa=false,fi=false;
	ll mini2=INF,maxi2=0;

	for(int i=0;i<n;i++){
		mini2=min(vec[i].second,mini2);
		maxi2=max(vec[i].first,maxi2);
	}
	ll res=(ll)(maxi-mini2)*(maxi2-mini);
	mini2=INF,maxi2=0;
	n_=1;
	while(n_<vec2.size()){
		n_*=2;
	}
	for(int i=0;i<vec2.size();i++){
		update(i,i+1,i);
		ll v=query(i,i+1);
	}
	for(int i=0;i<n;i++){
		vec[i].first=lower_bound(vec2.begin(),vec2.end(),vec[i].first)-vec2.begin();
		vec[i].second=lower_bound(vec2.begin(),vec2.end(),vec[i].second)-vec2.begin();
		update(0,vec[i].first+1,vec[i].first);
		update(vec[i].first+1,vec[i].second+1,vec[i].second);
		update(vec[i].second+1,vec2.size(),INF);
	}
	for(int i=0;i<vec2.size();i++){
		ll v=query(i,i+1);
		if(v!=INF){
			res=min(res,(maxi-mini)*(vec2[v]-vec2[i]));
		}
	}
	printf("%lld\n",res);
	return 0;
}
