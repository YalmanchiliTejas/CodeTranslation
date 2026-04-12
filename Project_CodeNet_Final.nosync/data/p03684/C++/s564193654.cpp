#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#define mp make_pair
typedef long long ll;
using namespace std;
int n,fa[100005],x[100005],y[100005];
pair<int,int> px[100005],py[100005];
vector<pair<int,pair<int,int> > > pe;
int gf(int x){
	if (fa[x]==x) return x; else return fa[x]=gf(fa[x]);
}
int Abs(int x){
	if (x>=0) return x; else return -x;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>px[i].first;
		x[i]=px[i].first;
		px[i].second=i;
		cin>>py[i].first;
		y[i]=py[i].first;
		py[i].second=i;
		fa[i]=i;
	}
	sort(px,px+n);
	sort(py,py+n);
	for (int i=0;i<n-1;i++){
		pe.push_back(mp(min(Abs(px[i+1].first-px[i].first),Abs(y[px[i+1].second]-y[px[i].second])),mp(px[i].second,px[i+1].second)));
		pe.push_back(mp(min(Abs(py[i+1].first-py[i].first),Abs(x[py[i+1].second]-x[py[i].second])),mp(py[i].second,py[i+1].second)));
	}
	sort(pe.begin(),pe.end());
	long long cnt=0;
	for (int i=0;i<pe.size();i++){
		gf(pe[i].second.second);
		gf(pe[i].second.first);
		if (fa[pe[i].second.first]!=fa[pe[i].second.second]){
			fa[gf(pe[i].second.second)]=gf(pe[i].second.first);
			cnt+=pe[i].first;
		}
	}
	cout<<cnt;
	return 0;
}