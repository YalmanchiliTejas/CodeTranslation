#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int N,num_query;
	int head_loc = 1;

	scanf("%d %d",&N,&num_query);

	int command,loc,tmp;

	for(int loop = 0; loop < num_query; loop++){

		scanf("%d %d",&command,&loc);

		if(command == 0){

			tmp = (head_loc+(loc-1))%N;
			if(tmp == 0){
				tmp = N;
			}
			printf("%d\n",tmp);

		}else{

			tmp = (head_loc+loc)%N;
			if(tmp == 0){
				tmp = N;
			}
			head_loc = tmp;
		}
	}

	return 0;
}

