#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
deque<int> que;

int main(void){
	scanf("%d",&n);
	bool flag=true;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(flag){
			que.push_back(a);
		}else{
			que.push_front(a);
		}
		flag=!flag;
	}
	if(flag){
		for(int i=0;i<n;i++){
			printf("%d%c",que[i],i==n-1?'\n':' ');
		}
	}
	if(!flag){
		for(int i=n-1;i>=0;i--){
			printf("%d%c",que[i],i==0?'\n':' ');
		}
	}
	return 0;
}
