#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N,M;
bool check[8][8];


int main(){

	scanf("%d %d",&N,&M);

	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){

			check[i][k] = false;
		}
	}

	int from,to;

	for(int i = 0; i < M; i++){

		scanf("%d %d",&from,&to);
		from--;
		to--;

		check[from][to] = true;
		check[to][from] = true;
	}

	vector<int> vec;
	for(int i = 1; i < N; i++){
		vec.push_back(i);
	}

	int ans = 0;
	bool FLG;

	do{

		int now = 0;
		FLG = true;

		for(int i = 0; i < vec.size(); i++){
			if(!check[now][vec[i]]){

				FLG = false;
				break;
			}
			now = vec[i];
		}

		if(FLG){

			ans++;
		}

	}while(next_permutation(vec.begin(),vec.end()));

	printf("%d\n",ans);

	return 0;
}
