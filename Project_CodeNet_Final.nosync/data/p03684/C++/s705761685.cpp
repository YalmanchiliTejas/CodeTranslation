#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>	
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#define INF 2000000000
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define mk make_pair
#define en endl
#define RE return 0
#define int ll
#define P pair<int,int>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int gcd(int a,int b){if(a%b==0){return b;}else return gcd(b,a%b);}
int lcm(int a,int b){if(a==0){return b;} return a/gcd(a,b)*b;}

#define MAX 100005

int x[MAX],y[MAX];
P sort_x[MAX],sort_y[MAX];
int dis[MAX];
vector<P> G[MAX];
int fin[MAX];

signed main(){
	int n; cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
		sort_x[i]=mk(x[i],i);
		sort_y[i]=mk(y[i],i);
	}
	sort(sort_x, sort_x+n);
	sort(sort_y, sort_y+n);
	for(int i=0; i<n; i++){
		P p=sort_x[i];
		if(i){
			G[p.second].push_back(mk(sort_x[i-1].second, abs(x[p.second]-sort_x[i-1].first)));
			G[sort_y[i].second].push_back(mk(sort_y[i-1].second, abs(y[sort_y[i].second]-sort_y[i-1].first)));
		}
		if(i!=n-1){
			G[p.second].push_back(mk(sort_x[i+1].second, abs(x[p.second]-sort_x[i+1].first)));
			G[sort_y[i].second].push_back(mk(sort_y[i+1].second, abs(y[sort_y[i].second]-sort_y[i+1].first)));
		}
	}
	
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(mk(0,0));
	int ans=0;
	while(!que.empty()){
		int now=que.top().second; int p=que.top().first; que.pop();
		if(fin[now]) continue;
		else{ 
			ans+=p; 
			fin[now]=true;
		}
		for(int i=0; i<G[now].size(); i++){
			int to=G[now][i].first, d=G[now][i].second;
			if(fin[to]) continue;
			que.push(mk(d,to));
		}
	}
	cout<<ans<<en;
}

