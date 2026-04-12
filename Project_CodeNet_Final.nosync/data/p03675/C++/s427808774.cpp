#include<bits/stdc++.h>
using namespace std;
#define ran 222222
int n;
deque<int> q;
int a[ran],la;
int main(){
	scanf("%d",&n);
	bool flag = true;
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		if(flag)
			q.push_back(x);
		else
			q.push_front(x);
		flag = !flag;
	}
	while(!q.empty()){
		a[la++] = q.front();
		q.pop_front();
	}
	if(!flag){
		reverse(a,a+la);
	}
	for(int i=0; i<la; i++)
		printf("%d%c",a[i],i<la-1?' ':'\n');
	return 0;
}
