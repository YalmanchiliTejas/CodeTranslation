#include<stdio.h>

typedef struct{
	int U,W,E,S,N,D;
}dice_t;

int t;

void shoki(dice_t* dice){//ダイスの初期位置
	dice->U=1;
	dice->W=4;
	dice->E=3;
	dice->S=2;
	dice->N=5;
	dice->D=6;
}

void N(dice_t* dice){
	t=dice->U;
	dice->U=dice->S;
	dice->S=dice->D;
	dice->D=dice->N;
	dice->N=t;
}

void E(dice_t* dice){
	t=dice->U;
	dice->U=dice->W;
	dice->W=dice->D;
	dice->D=dice->E;
	dice->E=t;
}

void W(dice_t* dice){
	t=dice->U;
	dice->U=dice->E;
	dice->E=dice->D;
	dice->D=dice->W;
	dice->W=t;
}

void S(dice_t* dice){
	t=dice->U;
	dice->U=dice->N;
	dice->N=dice->D;
	dice->D=dice->S;
	dice->S=t;
}

void R(dice_t* dice){
	t=dice->S;
	dice->S=dice->E;
	dice->E=dice->N;
	dice->N=dice->W;
	dice->W=t;
}

void L(dice_t* dice){
	t=dice->S;
	dice->S=dice->W;
	dice->W=dice->N;
	dice->N=dice->E;
	dice->E=t;
}

int main(void){
	char sousa[10];
	int i,n,s;
	dice_t dice;
	while(0==0){
		scanf("%d",&n);
		if(n==0) break;
		shoki(&dice);
		s=1;
		for(i=0;i<n;i++){
			scanf("%s",sousa);
			switch(sousa[0]){
			    case 'N':
				  N(&dice);
				  break;
				case 'E':
				  E(&dice);
				  break;
				case 'W':
				  W(&dice);
				  break;
				case 'S':
				  S(&dice);
				  break;
				case 'R':
				  R(&dice);
				  break;
				case 'L':
				  L(&dice);
				  break;
			}
			s+=dice.U;
		}
		printf("%d\n",s);
	}
	return 0;
}