#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n,x;
char s[8];
int main()
{for(;;){
	scanf("%d",&n);
	if(!n) return 0;
	int ans=1;
	int dice[6]={1,2,3,5,4,6};
	for(int i=0;i<n;i++){
		scanf("%s",s);
		if(strcmp(s,"North")==0){
			x=dice[0];
			dice[0]=dice[1];
			dice[1]=dice[5];
			dice[5]=dice[3];
			dice[3]=x;
		}
		else if(strcmp(s,"South")==0){
			x=dice[0];
			dice[0]=dice[3];
			dice[3]=dice[5];
			dice[5]=dice[1];
			dice[1]=x;
		}
		else if(strcmp(s,"East")==0){
			x=dice[0];
			dice[0]=dice[4];
			dice[4]=dice[5];
			dice[5]=dice[2];
			dice[2]=x;
		}
		else if(strcmp(s,"West")==0){
			x=dice[0];
			dice[0]=dice[2];
			dice[2]=dice[5];
			dice[5]=dice[4];
			dice[4]=x;
		}
		else if(strcmp(s,"Right")==0){
			x=dice[1];
			dice[1]=dice[2];
			dice[2]=dice[3];
			dice[3]=dice[4];
			dice[4]=x;
		}
		else{
			x=dice[1];
			dice[1]=dice[4];
			dice[4]=dice[3];
			dice[3]=dice[2];
			dice[2]=x;
		}
		ans+=dice[0];
	}
	printf("%d\n",ans);
}}