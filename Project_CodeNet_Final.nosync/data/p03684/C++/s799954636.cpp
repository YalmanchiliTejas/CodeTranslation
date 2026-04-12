#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
typedef pair<int,int> pii;
int n,f[100004];
pair<pii,int> x[100004];
vector <pair<long long,pii> > g;
int Find(int x){return (f[x]==x)?x:f[x]=Find(f[x]);}
void UNION(int x,int y){x=Find(x),y=Find(y);f[x]=y;}
int main(){
	cin>>n;
	for (int i=0;i<n;i++) f[i]=i;
	for (int i=0;i<n;i++){
		x[i].second=i;
		cin>>x[i].first.first>>x[i].first.second;
	}
	sort (x,x+n);
	for (int i=1;i<n;i++)
		g.push_back(mkp(1ll*x[i].first.first-1ll*x[i-1].first.first,mkp(x[i].second,x[i-1].second)));
	for (int i=0;i<n;i++)
		swap(x[i].first.first,x[i].first.second);
	sort (x,x+n);
	for (int i=1;i<n;i++)
		g.push_back(mkp(1ll*x[i].first.first-1ll*x[i-1].first.first,mkp(x[i].second,x[i-1].second)));
	long long ans=0;
	sort (g.begin(),g.end());
	for (int i=0;i<g.size();i++){
		pair<long long,pii> u1=g[i];
		int o1=u1.second.first,o2=u1.second.second;
		if (Find(o1)==Find(o2)) continue;
		else ans+=u1.first;
		UNION(o1,o2);
	}
	cout<<ans;
}