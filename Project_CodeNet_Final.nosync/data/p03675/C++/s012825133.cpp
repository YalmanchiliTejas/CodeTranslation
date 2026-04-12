#include <bits/stdc++.h>

using namespace std;

#define up(i,j,n)	for(int i=j;i<=n;i++)

int N,tag=0;
deque<int>S;

int main(){
//	freopen("input.in","r",stdin);
	scanf("%d",&N);
	up(i,1,N){
		int x;
		scanf("%d",&x);
		if(tag)S.push_back(x);
		else S.push_front(x);
		tag^=1;
	}
	if(!tag){
		while(!S.empty()){
			printf("%d ",S.back());
			S.pop_back();
		}
	}else {
		while(!S.empty()){
			printf("%d ",S.front());
			S.pop_front();
		}
	}
	puts("");
	return 0;
}