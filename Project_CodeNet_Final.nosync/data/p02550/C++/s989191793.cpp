#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,x,m;
	cin>>n>>x>>m;
	bool visited[100005]={false};
	deque<long long>deq;
	long long ret = 0;
	while(!visited[x]){
		visited[x] = true;
		deq.push_back(x);
		long long curr = x;
		curr*=curr;
		curr%=m;
		x=curr;
	}
	while(deq.front()!=x && n){
		ret+=deq.front();
		deq.pop_front();
		n--;
	}
	long long len = deq.size(); 
	long long val = 0;
	for(int i=0; i<len; i++){
		val+=deq.front();
		deq.push_back(deq.front());
		deq.pop_front();
	}
	ret+=(n/len)*val;
	n%=len;
	for(int i=0; i<n; i++){
		ret+=deq.front();
		deq.pop_front();
	}
	cout<<ret;
}