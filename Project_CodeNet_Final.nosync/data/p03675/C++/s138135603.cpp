#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
deque<int> Q;
int n;
int main(){
	scanf("%d", &n);
	bool rev=0; int a;
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		if(!rev) Q.push_back(a);
		else Q.push_front(a);
		rev^=1;
	}
	if(rev)
		for(deque<int>::reverse_iterator it=Q.rbegin();it!=Q.rend();it++)
			printf("%d ", *it);
	else
		for(deque<int>::iterator it=Q.begin();it!=Q.end();it++)
			printf("%d ", *it);
	puts("");
	return 0;
}