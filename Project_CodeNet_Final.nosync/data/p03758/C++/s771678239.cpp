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
	int i,j,k,N=200,chousei=4,a,b;
	vector<pair<int,int>> kotae;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j+=chousei){
			printf("? ");
			for(k=0;k<N;k++){
				if(k==i||(j<=k&&k<j+chousei)){a=1;} else{a=0;}
				printf("%d",a);
			}
			printf("\n");
			fflush(stdout);
			scanf("%d",&a);
			if(a!=0){
				for(k=j;k<min(j+chousei,N);k++){
					printf("? ");
					for(int l=0;l<N;l++){
						if(l==i||k==l){b=1;} else{b=0;}
						printf("%d",b);
					}
				printf("\n");
				fflush(stdout);
				scanf("%d",&b);
				if(b!=0){kotae.pub(mp(i,k));}
				}
			}
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

