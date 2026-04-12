#include <bits/stdc++.h>

using namespace std;

deque<int> dq;
deque<int>::iterator its;

int pos = 0, a;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		if(pos == 0) dq.push_back(a);
		else dq.push_front(a);
		pos = 1-pos;
	}

	if(pos == 0){
		while(!dq.empty()){
			printf("%d ", dq.front());
			dq.pop_front();
		}
	}
	else{
		while(!dq.empty()){
			printf("%d ", dq.back());
			dq.pop_back();
		}
	}
}