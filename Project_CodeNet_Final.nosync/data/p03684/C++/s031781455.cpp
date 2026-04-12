#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int n;cin>>n;
	vector<pair<long long,int>> x(n),y(n),r(n),u(n),d(n),l(n);
	for(int i=0;i<n;i++){
		cin>>x[i].first>>y[i].first;
		x[i].second=y[i].second=i;
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	l[x[0].second].second=-1;
	r[x[n-1].second].second=-1;
	u[y[n-1].second].second=-1;
	d[y[0].second].second=-1;
	for(int i=0;i<n-1;i++){
		r[x[i].second].second=x[i+1].second;
		r[x[i].second].first=x[i+1].first-x[i].first;
		l[x[i+1].second].second=x[i].second;
		l[x[i+1].second].first=x[i+1].first-x[i].first;
		u[y[i].second].second=y[i+1].second;
		u[y[i].second].first=y[i+1].first-y[i].first;
		d[y[i+1].second].second=y[i].second;
		d[y[i+1].second].first=y[i+1].first-y[i].first;

	}
	long long ans=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
	pair<long long,int> p,pt;
	vector<int> use(n,1);
	use[0]=0;
	if(r[0].second!=-1){
		q.push(r[0]);
	}
	if(l[0].second!=-1){
		q.push(l[0]);
	}
	if(u[0].second!=-1){
		q.push(u[0]);
	}
	if(d[0].second!=-1){
		q.push(d[0]);
	}
//	for(int i=0;i<n;i++){
//		cout<<r[i].first<<' '<<r[i].second<<endl;
//	}
	for(int i=1;i<n;i++){
		while(1){
			pt=q.top();
			q.pop();
			if(use[pt.second]){
				use[pt.second]=0;
				break;
			}
		}
		ans+=pt.first;
		if(r[pt.second].second!=-1){
			q.push(r[pt.second]);
		}
		if(l[pt.second].second!=-1){
			q.push(l[pt.second]);
		}
		if(u[pt.second].second!=-1){
			q.push(u[pt.second]);
		}
		if(d[pt.second].second!=-1){
			q.push(d[pt.second]);
		}
	}
	cout<<ans<<endl;
	return 0;
}