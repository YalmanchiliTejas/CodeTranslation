#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char g;
char fie[4][13];
int val[4][13];
int score[4];
int main(void){
	while(1){
		scanf("%c%*c",&g);
		if(g=='#')break;
		for(int i=0;i<4;i++){
			for(int j=0;j<13;j++){
				char a;
				scanf("%c%c%*c",&a,&fie[i][j]);
				if(a>='0' && a<='9'){
					val[i][j]=a-'0';
				}else{
					if(a=='T')val[i][j]=10;
					if(a=='J')val[i][j]=11;
					if(a=='Q')val[i][j]=12;
					if(a=='K')val[i][j]=13;
					if(a=='A')val[i][j]=14;
				}
			}
		}
		memset(score,0,sizeof(score));
		int lead=0;
		for(int i=0;i<13;i++){
			int win=-1,ws=-1;
			for(int j=0;j<4;j++){
				int sc=val[j][i];
				if(fie[j][i]==g)sc+=100;
				if(fie[j][i]!=g && fie[j][i]!=fie[lead][i])continue;
				if(sc>ws){
					ws=sc;
					win=j;
				}
			}
			lead=win;
			score[win]++;
		}
		if(score[0]+score[2]>score[1]+score[3]){
			printf("NS %d\n",score[0]+score[2]-6);
		}else{
			printf("EW %d\n",score[1]+score[3]-6);
		}
	}
	return 0;
}