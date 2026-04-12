#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void){
int n;
while(1){
	cin>>n;
	if(n==0)break;
	int b;
	priority_queue<int> a;
	for(int i=0;i<n;i++){
		cin>>b;
		a.push(b);
	}
	a.pop();
	int ans=0,c;
	while(a.size()!=1){
ans+=a.top();
a.pop();
	}
	ans/=n-2;
	cout<<ans<<endl;
}
	return 0;
}