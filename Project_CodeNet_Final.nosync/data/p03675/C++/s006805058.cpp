#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	deque<int> dq;
	bool flag=1;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(flag) dq.push_back(x);
		else dq.push_front(x);
		flag=!flag;
	}
	if(flag){
		cout<<dq.front();
		dq.pop_front();
		while(!dq.empty()){
			cout<<' '<<dq.front();
			dq.pop_front();
		}
		cout<<'\n';
	}else{
		cout<<dq.back();
		dq.pop_back();
		while(!dq.empty()){
			cout<<' '<<dq.back();
			dq.pop_back();
		}
		cout<<'\n';
	}
	return 0;
}