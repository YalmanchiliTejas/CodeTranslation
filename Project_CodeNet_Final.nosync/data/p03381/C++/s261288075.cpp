#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXN 200010
using namespace std;

int n;
int A[MAXN];
struct item{
	int num;
	int pos;
	inline bool operator <(item rhs) const{
		return num < rhs.num;
	}
};
item B[MAXN];
int C[MAXN];

int judge(int j){
	if(j > n / 2){
		return n / 2;
	}
	if(j <= n / 2) return n / 2 + 1;
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		int t;
		scanf("%d",&t);	
		A[i] = t;
		B[i].num = t;
		B[i].pos = i;
	}
	sort(B + 1,B + n + 1);
	for(int i = 1;i <= n;i++){
		int p = B[i].pos;
		C[p] = i;
	//	printf("[%d]%d\n",B[i].num,p);
	}
	//for(int i = 1;i <= n;i++){
	//	printf("[%d]\n",C[i]);
//	}	
	for(int i = 1;i <= n;i++){
		//printf("[%d]",judge(C[i]));
		printf("%d\n",B[judge(C[i])].num);
	}
	return 0;
} 