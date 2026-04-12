#include<deque>
#include<queue>
#include<map>
#include<string>
#include<iostream>
#include<set>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
//#define scanf scanf_s
#define fir first
#define sec second
#define mp make_pair
#define mt make_tuple
#define pub push_back
using namespace std;
typedef long long int llint;
const llint one = 1;
const llint big = (one<<30);
const llint mod=1000000007;

/*printf("? %c %c\n",x,y);
		fflush(stdout);
		char ret;scanf(" %c", &ret);
		*/
int main(void){
	int i,j,k,N=200,a;
	vector<pair<int,int>> kotae;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			printf("? ");
			for(k=0;k<N;k++){
				if(k==i||k==j){a=1;} else{a=0;}
				printf("%d",a);
			}
			printf("\n");
			fflush(stdout);
			scanf("%d",&a);
			if(a!=0){kotae.pub(mp(i,j));}
		}
	}
	printf("!");
	for(i=0;i<kotae.size();i++){
		printf(" (%d,%d)",kotae[i].first,kotae[i].second);
		
	}
	printf("\n");
	fflush(stdout);
	return 0;
}
