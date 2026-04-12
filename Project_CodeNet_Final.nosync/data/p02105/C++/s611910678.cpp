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


struct Info{
	Info(ll arg_weight,ll arg_value){
		weight = arg_weight;
		value = arg_value;
	}
	bool operator<(const struct Info &arg) const{
		return weight < arg.weight;
	}
	ll weight,value;
};

int N;
ll A,B;
vector<Info> V[5],G[2];

int main(){

	scanf("%d %lld %lld",&N,&A,&B);

	int type;
	ll x,y;

	for(int i = 0; i < 5; i++)V[i].push_back(Info(0,0)); //装備なし

	for(int loop = 0; loop < N; loop++){
		scanf("%d %lld %lld",&type,&x,&y);
		type--;
		V[type].push_back(Info(x,y));
	}

	for(int i = 0; i < V[0].size(); i++){
		for(int k = 0; k < V[1].size(); k++){
			G[0].push_back(Info(V[0][i].weight+V[1][k].weight,V[0][i].value+V[1][k].value));
		}
	}

	for(int a = 0; a < V[2].size(); a++){
		for(int b = 0; b < V[3].size(); b++){
			for(int c = 0; c < V[4].size(); c++){
				G[1].push_back(Info(V[2][a].weight+V[3][b].weight+V[4][c].weight,V[2][a].value+V[3][b].value+V[4][c].value));
			}
		}
	}

	sort(G[0].begin(),G[0].end());
	sort(G[1].begin(),G[1].end());

	int add_index = G[1].size()-1,del_index = G[1].size()-1;

	map<ll,int> count;
	set<ll> SET;

	for(int i = 0; i < G[0].size(); i++){

		while(add_index >= 0 && G[0][i].weight+G[1][add_index].weight >= A){
			SET.insert(G[1][add_index].value);
			count[G[1][add_index].value]++;
			add_index--;
		}

		while(del_index > add_index && G[0][i].weight+G[1][del_index].weight > B){
			count[G[1][del_index].value]--;
			if(count[G[1][del_index].value] == 0)SET.erase(G[1][del_index].value);
			del_index--;
		}

		if(SET.lower_bound(A-G[0][i].value) != SET.upper_bound(B-G[0][i].value)){
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");

	return 0;
}

