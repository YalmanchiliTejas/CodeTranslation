#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	deque<int> b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(i%2==0)b.push_back(x);
		else b.push_front(x);
	}
	if(n%2==0)for(i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	else for(i=n-1;i>=0;i--)printf("%d ",b[i]);
}
