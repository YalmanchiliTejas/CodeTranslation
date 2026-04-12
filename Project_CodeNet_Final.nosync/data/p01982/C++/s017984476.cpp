#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 4005

int N,L,R;
int table[NUM];

void func(){

	for(int i = 1; i <= N; i++){
		scanf("%d",&table[i]);
	}

	int ans = 0;
	int min_index;

	for(int x = L; x <= R; x++){

		min_index = BIG_NUM;

		for(int i = 1; i <= N; i++){
			if(x%table[i]== 0){
				min_index = i;
				break;
			}
		}

		if(min_index != BIG_NUM){

			if(min_index%2 == 1)ans++;

		}else{

			if(N%2 == 0)ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){

	while(true){
		scanf("%d %d %d",&N,&L,&R);
		if(N == 0 && L == 0 && R == 0)break;

		func();
	}

	return 0;
}

