#include <bits/stdc++.h>
using namespace std;
int main() {
	priority_queue<pair<int,int>> pq;
	int a,b;char c;
	while(cin>>a>>c>>b,a)
		pq.push(make_pair(b,a));
	int k[110];
	int before, cnt = 1;
	int n=pq.size();
	for(int i=0;i<n;i++){
		pair<int,int> p=pq.top();pq.pop();
		if(i==0){k[p.second]=1;}
		else if(before==p.first);else cnt++;
		k[p.second]=cnt;
		before=p.first;
	}
	int key;
	while(cin>>key){
		cout<<k[key]<<endl;
	}
	return 0;
}