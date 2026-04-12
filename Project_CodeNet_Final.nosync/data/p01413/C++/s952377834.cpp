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


#define NUM 8

struct Item{
	char name[8];
	int id,weight,value;
};

struct Info{
	int x,y,num_item;
	Item item[7];
};

struct Data{
	int time;
	ll profit;
};

int N,M,W,T;
int min_dist[NUM][NUM];
int POW[8],TSP[128][128][7];
Info info[8];
Data data[128];

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

void strcpy(char* to,char* str){
	for(int i=0;str[i] != '\0';i++){
		to[i] = str[i];
		to[i+1] = '\0';
	}
}

int main(){

	for(int i = 0; i < 8; i++)POW[i] = pow(2,i);

	scanf("%d %d %d %d",&N,&M,&W,&T);
	int market = N;

	for(int i = 0; i < M; i++){
		scanf("%s %d %d",info[market].item[i].name,&info[market].item[i].weight,&info[market].item[i].value);
	}

	char buf[8];
	int value;

	for(int i = 0; i < N; i++){
		scanf("%d %d %d",&info[i].num_item,&info[i].x,&info[i].y);
		for(int k = 0; k < info[i].num_item;k++){
			scanf("%s %d",buf,&value);

			for(int p = 0; p < M; p++){
				if(strCmp(info[market].item[p].name,buf)){
					info[i].item[k].id = p;
					info[i].item[k].value = value;
					break;
				}
			}
		}
	}

	info[market].x = 0;
	info[market].y = 0;

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= N; k++){
			min_dist[i][k] = abs(info[i].x-info[k].x)+abs(info[i].y-info[k].y);
		}
	}

	bool is_visit_town[N];
	ll knapsack[W+1];

	for(int group = 1; group < POW[N]; group++){

		for(int loop = 0; loop < N; loop++){
			if(group & (1 << loop)){
				is_visit_town[loop] = true;
			}else{
				is_visit_town[loop] = false;
			}
		}

		for(int state = 0; state <= group; state++){
			for(int i = 0; i < N; i++){
				if(!is_visit_town[i])continue;
				TSP[group][state][i] = BIG_NUM;
			}
		}

		for(int first_town = 0; first_town < N; first_town++){
			if(!is_visit_town[first_town])continue;
			TSP[group][POW[first_town]][first_town] = min_dist[market][first_town];
		}

		int next_state;

		for(int state = 1; state <= group; state++){
			for(int last_town = 0; last_town < N; last_town++){
				if(!is_visit_town[last_town])continue;
				if(TSP[group][state][last_town] == BIG_NUM)continue;

				for(int next_town = 0; next_town < N; next_town++){
					if(!is_visit_town[next_town])continue;
					if(state & (1 << next_town))continue;

					next_state = state+POW[next_town];

					TSP[group][next_state][next_town] = min(TSP[group][next_state][next_town],TSP[group][state][last_town]+min_dist[last_town][next_town]);
				}

			}
		}

		data[group].time = BIG_NUM;
		for(int last_town = 0; last_town < N; last_town++){
			if(!is_visit_town[last_town])continue;
			data[group].time = min(data[group].time,TSP[group][group][last_town]+min_dist[last_town][market]);
		}

		for(int i = 0; i <= W; i++)knapsack[i] = 0;

		int id;

		for(int town = 0; town < N; town++){
			if(!is_visit_town[town])continue;

			for(int i = 0; i < info[town].num_item; i++){
				id = info[town].item[i].id;
				if(info[town].item[i].value >= info[market].item[id].value)continue;

				for(int k = info[market].item[id].weight; k <= W; k++){
					knapsack[k] = max(knapsack[k],knapsack[k-info[market].item[id].weight]+info[market].item[id].value-info[town].item[i].value);
				}
			}
		}

		data[group].profit = 0;
		for(int i = 0; i <= W; i++)data[group].profit = max(data[group].profit,knapsack[i]);
	}

	ll final_knapsack[T+1];
	for(int i = 0; i <= T; i++)final_knapsack[i] = 0;

	for(int i = 1; i < POW[N]; i++){
		if(data[i].profit <= 0 || data[i].time > T)continue;

		for(int k = data[i].time; k <= T; k++){
			final_knapsack[k] = max(final_knapsack[k],final_knapsack[k-data[i].time]+data[i].profit);
		}
	}

	ll ans = 0;
	for(int i = 0; i <= T; i++)ans = max(ans,final_knapsack[i]);

	printf("%lld\n",ans);

	return 0;
}

