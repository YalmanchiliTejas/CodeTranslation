#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define mx(x,y) x=max(x,y)
int N,M,W,T;
string s[7];
int v[7],p[7],l[7],x[7],y[7],inf=1e9;
vector<int> itemid[7],itemp[7];
int dist(vector<int> towns){
	int mn=inf;
	int tn=towns.size();
	do{
		int now=abs(x[towns[0]])+abs(y[towns[0]]);
		rep(i,tn-1){
			now+=abs(x[towns[i+1]]-x[towns[i]])+abs(y[towns[i+1]]-y[towns[i]]);
		}
		now+=abs(x[towns[tn-1]])+abs(y[towns[tn-1]]);
		mn=min(mn,now);
	}while(next_permutation(all(towns)));
	return mn;
}
int knapsack(vector<int> items,vector<int> pro){
	int in=items.size();
	int dp[10001]={};
	rep(i,in){
		int id=items[i];
		rep(j,W+1){
			if(j+v[id]>W) break;
			mx(dp[j+v[id]],dp[j]+pro[i]);
		}
	}
	int ret=0;
	rep(j,W+1) mx(ret,dp[j]);
	return ret;
}
int dis[128],pro[128],dp[10001];
#undef int
int main(){
#define int long long
	cin>>N>>M>>W>>T;
	rep(i,M) cin>>s[i]>>v[i]>>p[i];
	rep(i,N){
		cin>>l[i]>>x[i]>>y[i];
		rep(j,l[i]){
			string rr;
			int pp;
			cin>>rr>>pp;
			rep(k,M){
				if(s[k]==rr){
					itemid[i].pb(k);
					itemp[i].pb(p[k]-pp);//benefit
				}
			}
		}
	}
	rep(i,1<<N){
		if(i==0) continue;
		vector<int> towns;
		rep(j,N) if((i>>j)&1) towns.pb(j);
		dis[i]=dist(towns);
		vector<int> pros(7,-inf);
		for(int u:towns){
			rep(k,l[u]){
				mx(pros[itemid[u][k]],itemp[u][k]);
			}
		}
		vector<int> items,prro;
		rep(j,M){
			if(pros[j]!=-inf){
				items.pb(j);
				prro.pb(pros[j]);
//				show(s[j]);
//				show(pros[j]);
			}
		}
		pro[i]=knapsack(items,prro);
//		show(i);
//		show(dis[i]);
//		show(pro[i]);
	}
	rep(i,1<<N){
		rep(j,T+1){
			if(j+dis[i]>T) break;
			mx(dp[j+dis[i]],dp[j]+pro[i]);
		}
	}
	int ans=0;
	rep(j,T+1) mx(ans,dp[j]);
	cout<<ans<<endl;
}