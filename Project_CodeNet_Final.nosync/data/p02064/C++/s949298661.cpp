#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 305

struct Info{
	Info(int arg_node_id,int arg_min_dist_from_S){
		node_id = arg_node_id;
		min_dist_from_S = arg_min_dist_from_S;
	}
	bool operator<(const struct Info &arg) const{

		return min_dist_from_S < arg.min_dist_from_S;
	}
	int node_id,min_dist_from_S;
};

int V;
int S,T;
int min_dist;
int min_dist_from_S[SIZE],min_dist_from_T[SIZE];

int main(){

	scanf("%d %d %d",&V,&S,&T);

	printf("? %d %d\n",S,T);
	cout.flush();
	scanf("%d",&min_dist);

	for(int i = 1; i <= V; i++){

		if(i == S || i == T)continue;
		printf("? %d %d\n",S,i);
		cout.flush();
		scanf("%d",&min_dist_from_S[i]);
	}

	for(int i = 1; i <= V; i++){

		if(i == S || i == T)continue;
		printf("? %d %d\n",T,i);
		cout.flush();
		scanf("%d",&min_dist_from_T[i]);
	}

	vector<Info> info;

	for(int i = 1; i <= V; i++){

		if(i == S || i == T)continue;

		if(min_dist_from_S[i]+min_dist_from_T[i] == min_dist){

			info.push_back(Info(i,min_dist_from_S[i]));
		}
	}
	sort(info.begin(),info.end());

	printf("! %d",S);

	for(int i = 0; i < info.size(); i++){

		printf(" %d",info[i].node_id);
	}

	printf(" %d\n",T);
	cout.flush();

	return 0;
}

