#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
 
int b[210000];
int c[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",b+i);
	}
	bool fi=true;
	for(int i=0;i<(a+1)/2;i++){
		if(!fi)printf(" ");
		fi=false;
		printf("%d",b[a-1-i*2]);
	}
	for(int i=0;i<a-(a+1)/2;i++){
		if(!fi)printf(" ");
		fi=false;
		printf("%d",b[(a)%2+i*2]);
	}
	printf("\n");
}