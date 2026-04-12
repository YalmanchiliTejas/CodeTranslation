#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005


int N;
bool FLG;
char buf[SIZE];
char table[SIZE],ans[SIZE];


void recursive(int loc){

	if(FLG)return;
	//printf("loc:%d table[loc]:%c\n",loc,table[loc]);

	if(loc == N){
		FLG = true;
		for(int i = 0; i < N; i++){

			ans[i] = table[i];
		}
		return;
	}

	if(table[loc] == 'S'){ //真実

		if(buf[loc] == 'o'){

			if(loc == 0){ //左右未定義

				table[N-1] = 'S';
				table[loc+1] = 'S';
				recursive(loc+1);

				table[N-1] = 'W';
				table[loc+1] = 'W';
				recursive(loc+1);

			}else if(loc == N-1){

				if(table[loc-1] != table[0]){

					return;

				}else{

					recursive(loc+1);
				}

			}else if(loc == N-2){ //次が決まっている

				if(table[loc-1] != table[loc+1]){

					return;

				}else{

					recursive(loc+1);
				}


			}else{ //右が未定義のはず

				table[loc+1] = table[loc-1];
				recursive(loc+1);
			}

		}else{ //buf[loc] == 'x' //左右が異なる動物

			if(loc == 0){ //左右未定義

				table[N-1] = 'S';
				table[loc+1] = 'W';
				recursive(loc+1);

				table[N-1] = 'W';
				table[loc+1] = 'S';
				recursive(loc+1);

			}else if(loc == N-1){

				if(table[loc-1] == table[0]){

					return;

				}else{

					recursive(loc+1);
				}

			}else if(loc == N-2){

				if(table[loc-1] == table[loc+1]){

					return;

				}else{

					recursive(loc+1);
				}


			}else{ //右が未定義のはず

				if(table[loc-1] == 'S'){

					table[loc+1] = 'W';

				}else{

					table[loc+1] = 'S';
				}
				recursive(loc+1);
			}
		}

	}else{ //嘘

		if(buf[loc] == 'o'){ //左右異なる

			if(loc == 0){ //左右未定義

				table[N-1] = 'W';
				table[loc+1] = 'S';
				recursive(loc+1);

				table[N-1] = 'S';
				table[loc+1] = 'W';
				recursive(loc+1);

			}else if(loc == N-1){

				if(table[loc-1] == table[0]){

					return;

				}else{

					recursive(loc+1);
				}

			}else if(loc == N-2){

				if(table[loc-1] == table[loc+1]){

					return;

				}else{

					recursive(loc+1);
				}


			}else{ //右が未定義のはず

				if(table[loc-1] == 'S'){

					table[loc+1] = 'W';

				}else{

					table[loc+1] = 'S';
				}
				recursive(loc+1);
			}

		}else{ //buf[loc] == 'x' //左右同じ

			if(loc == 0){ //左右未定義

				table[N-1] = 'S';
				table[loc+1] = 'S';
				recursive(loc+1);

				table[N-1] = 'W';
				table[loc+1] = 'W';
				recursive(loc+1);

			}else if(loc == N-1){

				if(table[loc-1] != table[0]){

					return;

				}else{

					recursive(loc+1);
				}

			}else if(loc == N-2){
				if(table[loc-1] != table[loc+1]){

					return;

				}else{

					recursive(loc+1);
				}


			}else{ //右が未定義のはず

				table[loc+1] = table[loc-1];
				recursive(loc+1);
			}
		}
	}
}

int main(){

	scanf("%d",&N);
	scanf("%s",buf);

	FLG = false;

	for(int loop = 0; loop < 2; loop++){
		if(FLG)break;
		for(int i = 0; i < N; i++){

			table[i] = '-';
		}
		if(loop == 0){

			table[0] = 'S';
			recursive(0);

		}else{

			table[0] = 'W';
			recursive(0);
		}
	}


	if(!FLG){

		printf("-1\n");

	}else{

		for(int i = 0; i < N; i++){

			printf("%c",ans[i]);
		}

		printf("\n");
	}

	return 0;
}
