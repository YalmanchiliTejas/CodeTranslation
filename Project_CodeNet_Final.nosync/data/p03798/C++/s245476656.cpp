#include<stdio.h>
#include<stdlib.h>

#define Nmax 100000 + 10

int N;
char s[Nmax];
char round[Nmax];
char animaltype[2] = {'S', 'W'}; 

int DP();

int main(){
	scanf("%d", &N);
	scanf("%s", s);
	int check = -1;
	for(int i = 0; i < 4; i++){
		round[0] = animaltype[i / 2];
		round[1] = animaltype[i % 2];
		check = DP();
		if(check == 0){
			break;
		}
	}
	if(check == 0){
		for(int i = 0; i < N; i++){
			printf("%c", round[i]);
		}
	}else{
		printf("-1");
	}
	system("pause");
	return 0;
}

int DP(){
	int buff;
	for(int i = 1; i < N; i++){
		buff = 0;
		if(round[i] == animaltype[1]){
			buff = 1;
		}
		if(round[i - 1] == animaltype[1]){
			buff = (buff + 1) % 2;
		}
		if(s[i] == 'x'){
			buff = (buff + 1) % 2;
		}
		if(i < N - 1){
			round[i + 1] = animaltype[buff];
		}else{
			if(round[0] != animaltype[buff]){
				return -1;
			}
		}
	}
	buff = 0;
	if(round[0] == animaltype[1]){
		buff = 1;
	}
	if(round[N - 1] == animaltype[1]){
		buff = (buff + 1) % 2;
	}
	if(s[0] == 'x'){
		buff = (buff + 1) % 2;
	}
	if(round[1] == animaltype[buff]){
		return 0;
	}else{
		return -1;
	}
}