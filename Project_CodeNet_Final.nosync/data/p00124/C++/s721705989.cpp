#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct tm_{
	char name[32];
	int s;
	bool operator<(const struct tm_ &r) {
		return s > r.s;
	}
}TM;
TM t[11];

int main(){
	bool st = true;
	int w,l,d;
	int n;
	while(scanf("%d",&n),n != 0){
		if(!st){
			printf("\n");
		}
		st = false;

		for(int i = 0; i < n; i++){
			scanf("%s%d%d%d",t[i].name,&w,&l,&d);
			t[i].s = w*3+d*1;
		}
		sort(t,t+n);
		for(int i = 0; i < n; i++){
			printf("%s,%d\n",t[i].name,t[i].s);
		}
	}
	return 0;
}

