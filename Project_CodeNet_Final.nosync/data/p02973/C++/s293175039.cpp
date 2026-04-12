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
map<int,int> MAP;


int main(){

	scanf("%d",&N);

	int ans = 0;

	int tmp;
	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);


		auto at = MAP.lower_bound(tmp); //自分以上の数

		if(at == MAP.begin()){ //自分より小さい数なし

			ans++;
			MAP[tmp]++;;

		}else{ //自分より小さい数あり

			at--;
			int work = at->first;
			MAP[work]--;
			if(MAP[work] == 0){

				MAP.erase(work);
			}
			MAP[tmp]++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
