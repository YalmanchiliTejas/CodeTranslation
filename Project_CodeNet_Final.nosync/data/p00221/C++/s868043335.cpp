#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 1005

int num_player,N;
bool check[SIZE];


int getNUM(char buf[10]){

	int ret = 0;

	for(int i = 0; buf[i] != '\0'; i++){

		ret = ret*10+(buf[i]-'0');
	}

	return ret;
}

bool isNUM(char buf[10]){

	for(int i = 0; buf[i] != '\0'; i++){
		if(buf[i] < '0' || buf[i] > '9'){
			return false;
		}
	}
	return true;
}


void func(){

	queue<int> Q;
	char buf[10];


	for(int i = 1; i <= num_player; i++){
		check[i] = false;
		Q.push(i);
	}

	int count = num_player;
	int tmp;

	for(int i = 1; i <= N; i++){

		scanf("%s",buf);

		if(count == 1)continue;

		tmp = Q.front();
		Q.pop();

		if(i%15 == 0){

			if(strcmp(buf,"FizzBuzz") == 0){
				Q.push(tmp);
			}else{

				count--;
			}

		}else if(i%3 == 0){

			if(strcmp(buf,"Fizz") == 0){
				Q.push(tmp);
			}else{
				count--;
			}

		}else if(i%5 == 0){

			if(strcmp(buf,"Buzz") == 0){

				Q.push(tmp);
			}else{

				count--;
			}

		}else{

			if((isNUM(buf) == true) & (getNUM(buf) == i)){

				Q.push(tmp);
			}else{

				count--;
			}
		}
	}

	while(!Q.empty()){

		check[Q.front()] = true;
		Q.pop();
	}

	bool isFirst = true;

	for(int i = 1; i <= num_player; i++){
		if(check[i]){

			if(isFirst){

				printf("%d",i);
				isFirst = false;
			}else{

				printf(" %d",i);
			}
		}
	}
	printf("\n");
}

int main(){

	while(true){
		scanf("%d %d",&num_player,&N);
		if(num_player == 0 && N == 0)break;

		func();
	}

	return 0;
}

