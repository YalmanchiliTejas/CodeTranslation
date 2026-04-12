#include<iostream>
#include<queue>
#include<cmath>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int n,m;
	while(1){
		cin>>n>>m;
		if(n==0 && m==0)break;
		priority_queue<int,vector<int>,greater<int> > que;
		que.push(0);
		int num;
		rep(i,n+m){
			cin>>num;
			que.push(num);
		}
		int timemax=0;
		while(que.size()>1){
			num=que.top();
			que.pop();
			timemax=max(timemax,que.top()-num);
		}
		cout<<timemax<<endl;
	}
	return 0;
}