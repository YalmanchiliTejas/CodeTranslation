#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
using namespace std;

struct Info{
	char mark,dist;
	int num;
};


int main(){

	char TRUMP[2],dealer;
	char buf[4];
	Info cards[4][13],work[4];
	for(int i = 0; i < 13; i++){
		cards[0][i].dist = 'N';
		cards[1][i].dist = 'E';
		cards[2][i].dist = 'S';
		cards[3][i].dist = 'W';
	}


	int ns,ew;

	while(true){
		scanf("%s",TRUMP);
		if(TRUMP[0] == '#')break;

		for(int i = 0;i < 4; i++){
			for(int k = 0; k < 13; k++){
				scanf("%s",buf);
				if(buf[0] == 'T'){
					cards[i][k].num = 10;
					cards[i][k].mark = buf[1];
				}else if(buf[0] == 'J'){
					cards[i][k].num = 11;
					cards[i][k].mark = buf[1];
				}else if(buf[0] == 'Q'){
					cards[i][k].num = 12;
					cards[i][k].mark = buf[1];
				}else if(buf[0] == 'K'){
					cards[i][k].num = 13;
					cards[i][k].mark = buf[1];
				}else if(buf[0] == 'A'){
					cards[i][k].num = 14;
					cards[i][k].mark = buf[1];
				}else{
					cards[i][k].num = buf[0] - '0';
					cards[i][k].mark = buf[1];
				}
			}
		}

		ns = 0,ew = 0;

		dealer = cards[0][0].mark;
		for(int i = 0; i < 13; i++){
			for(int k = 0; k < 4; k++){
				work[k] = cards[k][i];
			}

			for(int k = 1; k <= 3; k++){
				for(int p = 3; p >= k; p--){
					if(dealer == TRUMP[0]){
						if(work[p].mark ==dealer && work[p-1].mark != dealer){
							swap(work[p],work[p-1]);
						}else if(work[p].mark == dealer && work[p-1].mark == dealer && work[p].num > work[p-1].num){
							swap(work[p],work[p-1]);
						}
					}else{ //dealer != TRUMP[0]
						if(work[p].mark != TRUMP[0] && work[p-1].mark != TRUMP[0] && ((work[p].mark == dealer && work[p-1].mark != dealer) ||
								(work[p].mark == dealer && work[p-1].mark == dealer && work[p].num > work[p-1].num))){
							swap(work[p],work[p-1]);
						}else if(work[p].mark == TRUMP[0] && work[p-1].mark != TRUMP[0]){
							swap(work[p],work[p-1]);
						}else if(work[p].mark == TRUMP[0] && work[p-1].mark == TRUMP[0]&& work[p].num > work[p-1].num){
							swap(work[p],work[p-1]);
						}
					}
				}
			}
			switch(work[0].dist){
			case 'N':
				if(i <= 11){
					dealer = cards[0][i+1].mark;
				}
				ns++;
				break;
			case 'S':
				if(i <= 11){
					dealer = cards[2][i+1].mark;
				}
				ns++;
				break;
			case 'E':
				if(i <= 11){
					dealer = cards[1][i+1].mark;
				}
				ew++;
				break;
			case 'W':
				if(i <= 11){
					dealer = cards[3][i+1].mark;
				}
				ew++;
				break;
			}
		}

		if(ns > ew){
			printf("NS %d\n",ns-6);
		}else{
			printf("EW %d\n",ew-6);
		}
	}
    return 0;
}