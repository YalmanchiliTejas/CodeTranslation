#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct Info{
	int length;
	int count;
};


int main(){

	Info info[12];
	bool FLG;

	int index,tmp;

	scanf("%d",&tmp);

	info[0].length = tmp;
	info[0].count = 1;
	index = 1;


	for(int i = 1; i < 12; i++){
		scanf("%d",&tmp);
		FLG = false;
		for(int k = 0; k < index; k++){
			if(info[k].length == tmp){
				FLG = true;
				info[k].count++;
				break;
			}
		}
		if(!FLG){
			info[index].length = tmp;
			info[index].count = 1;
			index++;
		}

	}

	if(index >= 4){
		printf("no\n");
	}else if(index == 1){
		printf("yes\n");
	}else if(index == 2){
		if(info[1].count < info[0].count)swap(info[1],info[0]);
		if(info[0].count == 4 && info[1].count == 8){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}else{ //index == 3

		if(info[0].count == 4 && info[1].count == 4 && info[2].count == 4){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}