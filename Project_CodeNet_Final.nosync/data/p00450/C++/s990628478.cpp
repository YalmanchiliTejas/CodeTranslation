#include<stdio.h>
#include<stack>
using namespace std;
stack<int> s;
int main(){
	int n;
	int i;
	while(1){
	s.push(0);
	int c;
	scanf("%d",&n);
	if(n==0)return 0;
	scanf("%d",&c);
	for(i=1;i<n;i++){
		int nc;
		scanf("%d",&nc);
		if(i%2==0&&c!=nc){
			s.push(i);
		}
		else if(c!=nc){
			if(s.top()!=0)s.pop();
		}
		c=nc;
	}
	int p=n;
	int ans=0;
	while(!s.empty()){
		if(c==0)ans+=p-s.top();
		p=s.top();
		s.pop();
		c=(c+1)%2;
	}
	printf("%d\n",ans);
	}
}