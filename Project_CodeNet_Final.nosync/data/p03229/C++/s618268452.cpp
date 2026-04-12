#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b){ return (a<b ? (a=b)||1 : 0); }
int main() {
	
	deque<int> q;
	int n; cin>>n;
	for(int i=0; i<n; i++){
		int a; cin >>a;
		q.push_back(a);
	}
	sort(q.begin(),q.end());
	deque<int> p;
	p.push_back(q.back());
	q.pop_back();
	int64_t cnt{};
	while(!q.empty()){
		int tmp{}, c{1};
		if(chmax(tmp, abs(q.front()-p.front())))c=1;
		if(chmax(tmp, abs(q.front()-p.back())))c=2;
		if(chmax(tmp, abs(q.back()-p.front())))c=3;
		if(chmax(tmp, abs(q.back()-p.back())))c=4;
		if(c==1) {
			p.push_front(q.front());
			q.pop_front();
		}
		if(c==2) {
			p.push_back(q.front());
			q.pop_front();
		}
		if(c==3) {
			p.push_front(q.back());
			q.pop_back();
		}
		if(c==4) {
			p.push_back(q.back());
			q.pop_back();
		}
		cnt += tmp;
	}
	cout << cnt<<endl;
	
}