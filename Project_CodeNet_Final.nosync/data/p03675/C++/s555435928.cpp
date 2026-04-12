#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	deque<int> q;
	int head = 0;
	
	for(int i=0,v;i<n;i++){
		cin >> v;
		
		if(!head){
			q.push_front(v);
		}
		else{
			q.push_back(v);
		}
		head=1-head;
	}
	
	if(head){
		for(auto v:q){
			cout << v << " ";
		}
		cout << endl;
	}
	else{
		for(auto it=q.rbegin();it!=q.rend();it++){
			cout << *it << " ";
		}
		cout << endl;
	}
	
	return 0;
}