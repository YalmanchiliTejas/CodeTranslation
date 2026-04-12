#include<stdio.h>
#include<queue>
using namespace std;
deque<int> Q;
int n,a;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		if(i&1) Q.push_back(a);
		else Q.push_front(a);
	}
	if(n&1){
		while(!Q.empty()){
			printf("%d ",Q.back());
			Q.pop_back();
		}
	}
	else{
		while(!Q.empty()){
			printf("%d ",Q.front());
			Q.pop_front();
		}
	}
	return 0;
}
		
