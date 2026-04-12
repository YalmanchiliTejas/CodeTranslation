#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

struct Info{
	Info(){
		id = -1;
		rank = 0;
		num = -1;
	}
	int id,num,rank;

};

int main(){
	Info info[101];

	int id,number,result[101];

	while(true)
	{
		scanf("%d,%d",&id,&number);
		if(id == 0 && number == 0)break;

		info[id].num = number;
		info[id].id = id;
	}

	for(int i = 1; i <= 100; i++){
		for(int k=100; k >= i; k--){
			if(info[k].num > info[k-1].num)swap(info[k],info[k-1]);
		}
	}

	int rank = 0,tmp_num = 0;

	for(int i=0; i <= 100; i++){
		if(info[i].num != tmp_num){
			rank++;
			info[i].rank = rank;
			result[info[i].id] = rank;
			tmp_num = info[i].num;
		}else{
			info[i].rank = rank;
			result[info[i].id] = rank;
			tmp_num = info[i].num;
		}
	}

	int q;
	while(scanf("%d",&q)!=EOF){
		printf("%d\n",result[q]);
	}


	return 0;
}