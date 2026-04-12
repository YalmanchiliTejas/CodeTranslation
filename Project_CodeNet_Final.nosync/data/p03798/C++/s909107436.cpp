#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n, s1[100000], x[100000], e=0;
	char s[100000];
	scanf("%d", &n);
	scanf("%s", s);
	for(int i=0; i<n; i++){
		if(s[i]=='o'){
			s1[i]=1;
		}else{
			s1[i]=-1;
		}
	}
	x[0]=1, x[1]=1;
	for(int i=1; i<=n-2; i++){
		x[i+1]=x[i]*x[i-1]*s1[i];
	}
	if(x[0]==x[n-1]*x[n-2]*s1[n-1] && x[1]==x[0]*x[n-1]*s1[0]){
		e=1;
		for(int i=0; i<=n-1; i++){
			if(x[i]==1){
				printf("%c", 'S');
			}else{
				printf("%c", 'W');
			}
		}
		printf("\n");
	}
	if(e==0){
	x[0]=1, x[1]=-1;
	for(int i=1; i<=n-2; i++){
		x[i+1]=x[i]*x[i-1]*s1[i];
	}
	if(x[0]==x[n-1]*x[n-2]*s1[n-1] && x[1]==x[0]*x[n-1]*s1[0]){
		e=1;
		for(int i=0; i<=n-1; i++){
			if(x[i]==1){
				printf("%c", 'S');
			}else{
				printf("%c", 'W');
			}
		}
		printf("\n");
	}
	}
	if(e==0){
	x[0]=-1, x[1]=1;
	for(int i=1; i<=n-2; i++){
		x[i+1]=x[i]*x[i-1]*s1[i];
	}
	if(x[0]==x[n-1]*x[n-2]*s1[n-1] && x[1]==x[0]*x[n-1]*s1[0]){
		e=1;
		for(int i=0; i<=n-1; i++){
			if(x[i]==1){
				printf("%c", 'S');
			}else{
				printf("%c", 'W');
			}
		}
		printf("\n");
	}
	}
	if(e==0){
	x[0]=-1, x[1]=-1;
	for(int i=1; i<=n-2; i++){
		x[i+1]=x[i]*x[i-1]*s1[i];
	}
	if(x[0]==x[n-1]*x[n-2]*s1[n-1] && x[1]==x[0]*x[n-1]*s1[0]){
		e=1;
		for(int i=0; i<=n-1; i++){
			if(x[i]==1){
				printf("%c", 'S');
			}else{
				printf("%c", 'W');
			}
		}
		printf("\n");
	}
	}
	if(e==0){
		printf("%d\n", -1);
	}
	return 0;
}