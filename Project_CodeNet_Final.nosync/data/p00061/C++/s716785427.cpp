#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int main(){
	int num,ans,t,n,r=0;
	vector<vector<int> > rank(200);
	pii tp;
	char c;
	priority_queue<pii> data;

	while(cin>>num){
		cin>>c>>ans;
		if(!num && !ans) break;
		data.push(pii(ans,num));
	}

	tp=data.top();data.pop();
	t=tp.first;
	rank[0].push_back(tp.second);

	while(!data.empty()){
		tp=data.top();data.pop();
		if(t!=tp.first){
			r++;
			t=tp.first;
		}
		rank[r].push_back(tp.second);
		t=tp.first;
	}

	while(cin>>n){
		for(int i=0;i<rank.size();i++){
			if(find(rank[i].begin(),rank[i].end(),n) != rank[i].end()){
				cout<<i+1<<endl;
			}
		}
	}

	return 0;
}