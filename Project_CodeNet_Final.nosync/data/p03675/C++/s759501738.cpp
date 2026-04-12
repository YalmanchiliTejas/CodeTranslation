#include <bits/stdc++.h>

#define N 100009

using namespace std;

deque<int> q;
vector<int> final;

int main(){
	int i,j,t1,t2,t3,t4,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t1);
		if(i%2){
			q.push_back(t1);
		}
		else{
			q.push_front(t1);
		}
	}
	for(auto it : q){
		final.push_back(it);
	}
	if(n%2==0){
		reverse(final.begin(),final.end());
	}
	for(auto it : final){
		printf("%d ",it);
	}
	printf("\n");
    return 0;
}