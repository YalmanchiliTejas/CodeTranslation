#include <stdio.h>
#include <stack>
#include <math.h>

using namespace std;



int main(){

	int gozen,gogo,most_value,most_index;

	while(true){
		scanf("%d %d",&gozen,&gogo);
		if(gozen == 0 && gogo == 0)break;

		most_value = gozen+gogo;
		most_index = 0;

		for(int i=1; i <= 4; i++){
			scanf("%d %d",&gozen,&gogo);

			if(most_value < gozen + gogo){
				most_value = gozen + gogo;
				most_index = i;
			}
		}

		switch(most_index){
		case 0:printf("A ");break;
		case 1:printf("B ");break;
		case 2:printf("C ");break;
		case 3:printf("D ");break;
		case 4:printf("E ");break;
		}

		printf("%d\n",most_value);
	}



    return 0;
}