#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("readin.txt","r",stdin);
	int n;
	deque<int>q;
	scanf("%d",&n);
	bool l = 1;
	for(int i = 0;i < n;i++){
		int a;
		scanf("%d",&a);
		if(l) q.push_front(a);
		else q.push_back(a);
		l^=1;
	}
	if(!l)
		while(!q.empty()){
			printf("%d ",q.front());
			q.pop_front();
		}
	else
		while(!q.empty()){
			printf("%d ",q.back());
			q.pop_back();
		}
}