#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
using namespace std;

struct Info{
	Info(ll arg_value,int arg_loc){
		value = arg_value;
		loc = arg_loc;
	}
	bool operator<(const struct Info &arg) const{
			return value < arg.value;
	};
	ll value;
	int loc;
};

int main(){

	int N;
	scanf("%d",&N);

	ll sum = 0,tmp;
	priority_queue<Info> Q;

	Q.push(Info(0,0));

	for(int i = 1; i <= N; i++){
		scanf("%lld",&tmp);
		sum += tmp;
		Q.push(Info(sum,i));
	}

	ll pre = -1;
	int maximum = 0,min_index = -1,max_index = -1;

	while(!Q.empty()){
		if(pre == Q.top().value){
			min_index = min(min_index,Q.top().loc);
			max_index = max(max_index,Q.top().loc);
		}else{
			if(min_index != max_index){
				maximum = max(maximum,max_index - min_index);
			}
			min_index = Q.top().loc;
			max_index = Q.top().loc;
		}

		pre = Q.top().value;
		Q.pop();
	}
	if(min_index != max_index){
		maximum = max(maximum,max_index - min_index);
	}

	printf("%d\n",maximum);

	return 0;
}