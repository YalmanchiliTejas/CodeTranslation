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
int n,fa[100005];
pair <int,int> px[100005],py[100005];
set <pair<int,pair<int,int> > > st;
int gf(int x){
	if (fa[x]==x) return x; else return fa[x]=gf(fa[x]);
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>px[i].first;
		px[i].second=i;
		cin>>py[i].first;
		py[i].second=i;
		fa[i]=i;
	}
	sort(px,px+n);
	sort(py,py+n);
	for (int i=0;i<n-1;i++){
		st.insert(mp(px[i+1].first-px[i].first,mp(px[i+1].second,px[i].second)));
		st.insert(mp(py[i+1].first-py[i].first,mp(py[i+1].second,py[i].second)));  
	}
	long long cnt=0;
	for (set<pair<int,pair<int,int> > >::iterator it=st.begin();it!=st.end();it++){
		if (gf(it->second.first)!=gf(it->second.second)){
			fa[gf(it->second.first)]=fa[gf(it->second.second)];
			cnt+=it->first;
		}
	}
	cout<<cnt;
	return 0;
}