#include <iostream>
#include <cstdio>
#include <stack>

#define MAX_N 100000

using namespace std;

typedef struct data{
	int kind;
	int num;
	data(){}
	data(int _kind,int _num){
		kind = _kind;
		num = _num;
	}

}data;


stack<data> stk;

int N;
int field[MAX_N + 1];

void add(int kind){
	if(stk.empty()){
		stk.push(data(kind,1));
		return ;
	}
	data d = stk.top();
	if(d.kind == kind){
		d.num++;
		stk.pop();
		stk.push(d);
	}
	else{
		stk.push(data(kind,1));
	}
	return ;
}

void query(int kind){
	if(stk.empty()){
		stk.push(data(kind,1));
		return ;
	}
	data d = stk.top();stk.pop();
	if(d.kind == kind){
		d.num++;
		stk.push(d);
	}
	else{
		d.kind = kind;
		d.num++;
		if(!stk.empty()){
			data d2 = stk.top();stk.pop();
			d.num += d2.num;
		}
		stk.push(d);
	}
	return ;
}

int main(){

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		for(int i = 1;i <= N;i++){
			scanf("%d",field + i);
		}
		for(int i = 1;i <= N;i++){
			if(i % 2 == 1){
				add(field[i]);
			}
			else{
				query(field[i]);
			}
			//printf("###%d:::%d\n",stk.top().kind,stk.top().num);
		}
		
		int ans = 0;
		while(!stk.empty()){
			data d = stk.top();stk.pop();
			if(d.kind == 0) ans += d.num;
		}

		printf("%d\n",ans);
	
	}

	return 0;
}