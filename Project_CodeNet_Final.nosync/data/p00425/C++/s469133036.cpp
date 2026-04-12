#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int n;
char input[10];
int ans;

int dice[6];		//上面,前面,右面,後面,左面,下面
int copy_dice[6];

void ini(){
	dice[0] = 1;
	dice[1] = 2;
	dice[2] = 3;
	dice[3] = 5;
	dice[4] = 4;
	dice[5] = 6;
}

//前面1→上面0→後面3→下面5
//上面0→後面3→下面5→前面1
void North(){
	int i;
	copy_dice[0] = dice[1];
	copy_dice[3] = dice[0];
	copy_dice[5] = dice[3];
	copy_dice[1] = dice[5];
	copy_dice[2] = dice[2];
	copy_dice[4] = dice[4];
	for( i = 0; i < 6; i++ )
		dice[i] = copy_dice[i];
}

//上面0→右面2→下面5→左面4
//右面2→下面5→左面4→上面0
void East(){
	int i;
	copy_dice[2] = dice[0];
	copy_dice[5] = dice[2];
	copy_dice[4] = dice[5];
	copy_dice[0] = dice[4];
	copy_dice[1] = dice[1];
	copy_dice[3] = dice[3];
	for( i = 0; i < 6; i++ )
		dice[i] = copy_dice[i];
}

//上面0→後面3→下面5→前面1
//前面1→上面0→後面3→下面5
void South(){
	int i;
	copy_dice[1] = dice[0];
	copy_dice[0] = dice[3];
	copy_dice[3] = dice[5];
	copy_dice[5] = dice[1];
	copy_dice[2] = dice[2];
	copy_dice[4] = dice[4];
	for( i = 0; i < 6; i++ )
		dice[i] = copy_dice[i];
}

//右面2→下面5→左面4→上面0
//上面0→右面2→下面5→左面4
void West(){
	int i;
	copy_dice[0] = dice[2];
	copy_dice[2] = dice[5];
	copy_dice[5] = dice[4];
	copy_dice[4] = dice[0];
	copy_dice[1] = dice[1];
	copy_dice[3] = dice[3];
	for( i = 0; i < 6; i++ )
		dice[i] = copy_dice[i];
}

//前面1→右面2→後面3→左面4
//左面4→前面1→右面2→後面3
void Right(){
	int i;
	copy_dice[4] = dice[1];
	copy_dice[1] = dice[2];
	copy_dice[2] = dice[3];
	copy_dice[3] = dice[4];
	copy_dice[0] = dice[0];
	copy_dice[5] = dice[5];
	for( i = 0; i < 6; i++ )
		dice[i] = copy_dice[i];
}

//左面4→前面1→右面2→後面3
//前面1→右面2→後面3→左面4
void Left(){
	int i;
	copy_dice[1] = dice[4];
	copy_dice[2] = dice[1];
	copy_dice[3] = dice[2];
	copy_dice[4] = dice[3];
	copy_dice[0] = dice[0];
	copy_dice[5] = dice[5];
	for( i = 0; i < 6; i++ )
		dice[i] = copy_dice[i];
}

void (*pf[6])() = {North,East,West,South,Right,Left};
char *type[6] = {"North","East","West","South","Right","Left"};

int main(){
	int i,j;
	
	while( scanf("%d",&n) ){
		if( !n )break;
		ans = 1;
		ini();
		
		for( i = 0; i < n; i++ ){
			scanf("%s",input);
			for( j = 0; j < 6; j++ ){
				if( strcmp( input, type[j] ) == 0 )
					break;
			}
			pf[j]();
			//printf("%d\n",dice[0]);
			ans += dice[0];
		}
		printf("%d\n",ans);
	}
	return 0;
}