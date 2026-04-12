#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100001

map<string,int> MAP;

struct Info{
	bool operator<(const struct Info &arg) const{
		return value > arg.value;
	}
	int value;
	string name;
	bool is_favorite;
};

int N,M,K,L;
int ally[NUM],enemy[NUM];
Info info[NUM];



bool strCmp(char* base, char* comp){
	int length1,length2;
	for(length1=0;base[length1] != '\0';length1++);
	for(length2=0;comp[length2] != '\0';length2++);
	if(length1 != length2)return false;

	for(int i=0;base[i] != '\0'; i++){
		if(base[i] != comp[i])return false;
	}
	return true;
}

bool is_OK(int num){

	int sum = 0;

	if(ally[num-1] <= K-1)return true;

	int base_loc = enemy[K-num];

	for(int i = 0; i < num; i++){
		if(info[ally[i]].value > info[base_loc].value){
			sum += 0;
		}else if(info[ally[i]].value == info[base_loc].value){
			if(info[ally[i]].name < info[base_loc].name){
				sum += 0;
			}else{
				sum += 1;
			}
		}else{
			if(info[ally[i]].name < info[base_loc].name){
				sum += info[base_loc].value-info[ally[i]].value;
			}else{
				sum += info[base_loc].value-info[ally[i]].value+1;
			}
		}
		if(sum > L)return false;
	}
	return true;
}


void func(){

	MAP.clear();

	char buf[11];

	for(int i = 0; i < N; i++){
		scanf("%s %d",buf,&info[i].value);
		info[i].name = buf;
		info[i].is_favorite = false;
		MAP[info[i].name] = i;
	}

	string name;
	for(int loop = 0; loop < M; loop++){
		scanf("%s",buf);
		name = buf;
		info[MAP[name]].is_favorite = true;
	}

	sort(info,info+N);

	for(int i = 0; i < NUM; i++){
		ally[i] = BIG_NUM;
		enemy[i] = BIG_NUM;
	}

	int ally_index = 0,enemy_index = 0;

	for(int i = 0; i < N;i++){
		if(info[i].is_favorite){
			ally[ally_index++] = i;
		}else{
			enemy[enemy_index++] = i;
		}
	}


	int left = 0,right = min(K,M),m = (left+right)/2;
	int ans = 0;

	while(left <= right){
		if(is_OK(m)){
			ans = m;
			left = m+1;
		}else{
			right = m-1;
		}
		m = (left+right)/2;
	}
	printf("%d\n",ans);
}

int main(){

	while(true){
		scanf("%d %d %d %d",&N,&M,&K,&L);
		if(N == 0 && M == 0 && K == 0 && L == 0)break;

		func();
	}

	return 0;
}

