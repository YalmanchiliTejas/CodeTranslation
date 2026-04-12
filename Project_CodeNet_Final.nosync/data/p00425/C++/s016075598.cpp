//dice
#include<stdio.h>
int dice[6];
void swap(int a, int b, int c, int d){
    int temp;

    temp = dice[a];
    dice[a] = dice[b];
    dice[b] = dice[c];
    dice[c] = dice[d];
    dice[d] = temp;
}

int main(void) {
	int n,i,r;
	char s[8];
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		r=1;
		dice[0] = 1;
		dice[1] = 2;
		dice[2] = 3;
		dice[3] = 5;
		dice[4] = 4;
		dice[5] = 6;
		for(i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]=='N'){
				swap(0, 1, 5, 3);
			}else if(s[0]=='E'){
				swap(0, 4, 5, 2);
			}else if(s[0]=='W'){
				swap(0, 2, 5, 4);
			}else if(s[0]=='S'){
				swap(0, 3, 5, 1);
			}else if(s[0]=='R'){
				swap(1, 2, 3, 4);
			}else{
				swap(1, 4, 3, 2);
			}
			r+=dice[0];
		}
		printf("%d\n",r);
	}
	return 0;
}