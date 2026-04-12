#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void func(int up, int down){
	int array_up[up],array_down[down],merge[up+down+1];

	for(int i = 0; i < up; i++){
		scanf("%d",&array_up[i]);
	}

	for(int i = 0; i < down; i++){
		scanf("%d",&array_down[i]);
	}

	merge[0] = 0;
	int p_up = 0,p_down = 0;
	for(int i = 1; i <= up+down; i++){
		if((p_down >= down)|| (p_up < up && array_up[p_up] <= array_down[p_down])){
			merge[i] = array_up[p_up];
			p_up++;
		}else{
			merge[i] = array_down[p_down];
			p_down++;
		}
	}

	int ans = 0;
	for(int i = 1; i <= up+down;i++){
		ans = max(ans,merge[i] - merge[i-1]);
	}

	printf("%d\n",ans);

}

int main(){

	int up,down;

	while(true){
		scanf("%d %d",&up,&down);
		if(up == 0 && down == 0)break;

		func(up,down);
	}

    return 0;
}