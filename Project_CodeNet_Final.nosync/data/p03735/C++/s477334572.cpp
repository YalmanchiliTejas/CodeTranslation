#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[222222];
pair<int,int> y[222222];
multiset<int> s,s2;
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		a[i] = make_pair(x,y);
	}
	sort(a,a+n);
	for(int i=0; i<n; i++){
		s.insert(a[i].first);
		s2.insert(a[i].second);
	}

	for(int i=0; i<n; i++)
		y[i] = make_pair(a[i].second, i);
	sort(y,y+n);

	long long int res = (long long int)((*s2.rbegin() - *s2.begin())) * ((*s.rbegin()) - (*s.begin()));
	for(int i=n-1; i>=0; i--){
		int id = y[i].second;
		if(id == 0)break;
		s.erase(s.find(a[id].first));
		s.insert(a[id].second);

		s2.erase(s2.find(a[id].second));
		s2.insert(a[id].first);
		res = min(res, (long long int)((*s2.rbegin() - *s2.begin())) * ((*s.rbegin()) - (*s.begin())));
	}
	cout << res <<endl;
	return 0;
}
