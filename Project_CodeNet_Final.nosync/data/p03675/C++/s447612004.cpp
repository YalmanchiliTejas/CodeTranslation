#include<deque>
#include<cstdio>
using namespace std;
deque<int> q;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		if(i%2) q.push_back(x); else q.push_front(x);
	}
	if(n%2)
		for(;!q.empty();q.pop_back()) printf("%d ",q.back());
	else for(;!q.empty();q.pop_front()) printf("%d ",q.front());
	return 0;
}