#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int m,n;
	while(scanf("%d %d",&m,&n),m) {
		bool die[1000]={0};
		int idx=0,M=m;
		for(int i=1;i<=n;i++) {
			char s[10];
			scanf("%s",s);
			if(M==1) continue;
			if(i%15==0) {
				if(strcmp(s,"FizzBuzz")!=0) die[idx]=1,M--;
			}else if(i%3==0) {
				if(strcmp(s,"Fizz")!=0) die[idx]=1,M--;
			}else if(i%5==0) {
				if(strcmp(s,"Buzz")!=0) die[idx]=1,M--;
			}else {
				if(i!=atoi(s)) die[idx]=1,M--;
			}
			do {idx=(idx+1)%m;}while(die[idx]);
		}
		idx=0;
		while(die[idx]) idx++;
		printf("%d",idx+1);
		for(int i=idx+1;i<m;i++) {
			if(!die[i]) printf(" %d",i+1);
		}
		printf("\n");
	}
}