#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct Team{
	char name[21];
	int score;
};

int main(){

	int n,win,lose,even;
	bool First = true;

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		if(!First)printf("\n");

		Team array[n];

		for(int i=0; i < n; i++){
			scanf("%s %d %d %d",array[i].name,&win,&lose,&even);
			array[i].score = 3*win+even;
		}

		for(int i=1; i <= n-1; i++){
			for(int k=n-1; k >= i; k--){
				if(array[k].score > array[k-1].score)swap(array[k],array[k-1]);
			}
		}
		for(int i=0; i< n; i++){
			printf("%s,%d\n",array[i].name,array[i].score);
		}

		if(First)First = false;
	}

    return 0;
}