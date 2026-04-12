#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n, inp;
	long long res1=0, res2=0;
	priority_queue <int> q1, q2;
	cin>>n;
	for(int i = 0;i < n;i ++){
		cin>>inp;
		q1.push(inp);
		q2.push(-inp);
	}
	if(n&1){
		for(int i = 0;i < n/2;i ++){
			res1+=q1.top()*2;
			q1.pop();
			res2-=-q2.top()*2;
			q2.pop();
		}
		res1-=q1.top();
		q1.pop();
		res1-=q1.top();
		q1.pop();
		res2+=-q2.top();
		q2.pop();
		res2+=-q2.top();
		q2.pop();
		for(int i = 1;i < n/2;i ++){
			res1-=q1.top()*2;
			q1.pop();
			res2+=-q2.top()*2;
			q2.pop();
		}
		printf("%lld\n",max(res1,res2));
	}else{
		for(int i = 1;i < n/2;i ++){
			res1+=2*q1.top();
			q1.pop();
		}
		res1+=q1.top();
		q1.pop();
		res1-=q1.top();
		q1.pop();
		for(int i = 1;i < n/2;i ++){
			res1-=2*q1.top();
			q1.pop();
		}
		printf("%lld\n",max(res1,res2));
	}
}