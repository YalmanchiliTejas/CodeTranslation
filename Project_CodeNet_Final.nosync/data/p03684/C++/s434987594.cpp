#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl;
#else
#define tr(a)    
#endif
#define int 		long long
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

void solve(){
	int N;
	cin>>N;
	map<int,vi>row;
	map<int,vi>col;
	set<int>s1,s2;
	rep(i,0,N){
		int a,b;
		cin>>a>>b;
		row[a].pb(i+1);
		col[b].pb(i+1);
	}
	vi dsu(N+1,-1);
	for(auto& i:row){
		rep(j,1,sz(i.S)){
			int a=i.S[j];
			int b=i.S[j-1];
			while(dsu[a]>0)a=dsu[a];
			while(dsu[b]>0)b=dsu[b];
			if(a==b)continue;
			if(dsu[a]<dsu[b]){
				dsu[a]+=dsu[b];
				dsu[b]=a;
			}
			else{
				dsu[b]+=dsu[a];
				dsu[a]=b;
			}
		}
	}
	for(auto& i:col){
		rep(j,1,sz(i.S)){
			int a=i.S[j];
			int b=i.S[j-1];
			while(dsu[a]>0)a=dsu[a];
			while(dsu[b]>0)b=dsu[b];
			if(a==b)continue;
			if(dsu[a]<dsu[b]){
				dsu[a]+=dsu[b];
				dsu[b]=a;
			}
			else{
				dsu[b]+=dsu[a];
				dsu[a]=b;
			}
		}
	}
	ll ans=0;
	vector<pii>temprownums,tempcolnums;
	for(auto& i:row)temprownums.pb(mp(i.F,i.S[0]));
	for(auto& i:col)tempcolnums.pb(mp(i.F,i.S[0]));
	vector<pair<int,pii>>rownums,colnums;
	rep(i,1,sz(temprownums)){
		rownums.pb(mp(temprownums[i].F-temprownums[i-1].F,mp(temprownums[i].S,temprownums[i-1].S)));
	}
	rep(i,1,sz(tempcolnums)){
		colnums.pb(mp(tempcolnums[i].F-tempcolnums[i-1].F,mp(tempcolnums[i].S,tempcolnums[i-1].S)));
	}
	sort(all(rownums));
	sort(all(colnums));
	int a=0;
	int b=0;
	while(a<rownums.size() and b<colnums.size()){
		if(rownums[a].F<colnums[b].F){
			int curx=rownums[a].S.F;
			int cury=rownums[a].S.S;
			int toadd=rownums[a].F;
			a++;
			while(dsu[curx]>0)curx=dsu[curx];
			while(dsu[cury]>0)cury=dsu[cury];
			if(curx==cury)continue;
			ans+=toadd;
			if(dsu[curx]<dsu[cury]){
				dsu[curx]+=dsu[cury];
				dsu[cury]=curx;
			}
			else{
				dsu[cury]+=dsu[curx];
				dsu[curx]=cury;
			}
		}
		else{
			int curx=colnums[b].S.F;
			int cury=colnums[b].S.S;
			int toadd=colnums[b].F;
			b++;
			while(dsu[curx]>0)curx=dsu[curx];
			while(dsu[cury]>0)cury=dsu[cury];
			if(curx==cury)continue;
			ans+=toadd;
			if(dsu[curx]<dsu[cury]){
				dsu[curx]+=dsu[cury];
				dsu[cury]=curx;
			}
			else{
				dsu[cury]+=dsu[curx];
				dsu[curx]=cury;
			}	
		}
	}
	while(a<rownums.size()){
		int curx=rownums[a].S.F;
		int cury=rownums[a].S.S;
		int toadd=rownums[a].F;
		a++;
		while(dsu[curx]>0)curx=dsu[curx];
		while(dsu[cury]>0)cury=dsu[cury];
		if(curx==cury)continue;
		ans+=toadd;
		if(dsu[curx]<dsu[cury]){
			dsu[curx]+=dsu[cury];
			dsu[cury]=curx;
		}
		else{
			dsu[cury]+=dsu[curx];
			dsu[curx]=cury;
		}
	}
	while(b<colnums.size()){
		int curx=colnums[b].S.F;
		int cury=colnums[b].S.S;
		int toadd=colnums[b].F;
		b++;
		while(dsu[curx]>0)curx=dsu[curx];
		while(dsu[cury]>0)cury=dsu[cury];
		if(curx==cury)continue;
		ans+=toadd;
		if(dsu[curx]<dsu[cury]){
			dsu[curx]+=dsu[cury];
			dsu[cury]=curx;
		}
		else{
			dsu[cury]+=dsu[curx];
			dsu[curx]=cury;
		}	
	}
	cout<<ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}