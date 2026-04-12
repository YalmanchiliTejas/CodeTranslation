#include <stdio.h>

typedef struct{
	int t_num;
	int score;
}t_team;

int main(void){
	t_team team[100000];
	int num = 0;
	int q;

	while(1){
		scanf("%d,%d", &(team[num].t_num), &(team[num].score));
		if(team[num].t_num == 0 && team[num].score == 0) break;
		num++;
	}
	for(int i=num-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(team[j].score < team[j+1].score){
				t_team temp = team[j];
				team[j] = team[j+1];
				team[j+1] = temp;
			}
		}
	}

	while(scanf("%d", &q) != EOF){
		int before = -1;
		int rank = 0;
		for(int i=0; i<num; i++){
			if(team[i].score != before){
				rank++;
				before = team[i].score;
			}
			if(team[i].t_num == q){
				printf("%d\n", rank);
				break;
			}
		}
	}

	return 0;
}