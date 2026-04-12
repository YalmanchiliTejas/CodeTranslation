#include<stdio.h>
char str[13][4][3];
int num[13][4];
char pro[2];
int main(){
	while(1){
		scanf("%s",pro);
		if(pro[0]=='#')return 0;
		for(int i=0;i<4;i++)
			for(int j=0;j<13;j++)
				scanf("%s",str[j][i]);
		for(int i=0;i<13;i++)
			for(int j=0;j<4;j++){
				if(str[i][j][0]=='A')num[i][j]=14;
				else if(str[i][j][0]=='K')num[i][j]=13;
				else if(str[i][j][0]=='Q')num[i][j]=12;
				else if(str[i][j][0]=='J')num[i][j]=11;
				else if(str[i][j][0]=='T')num[i][j]=10;
				else num[i][j]=str[i][j][0]-'0';
				if(str[i][j][1]==pro[0])num[i][j]+=40;
			}
		int ns=0;
		int ew=0;
		int at=0;
		for(int i=0;i<13;i++){
			char c=str[i][at][1];
			int n=at;
			int p=num[i][at];
			for(int j=1;j<4;j++){
				if((c==str[i][(at+j)%4][1]||num[i][(at+j)%4]>40)){
					if(p<num[i][(at+j)%4]){
						p=num[i][(at+j)%4];
						n=(at+j)%4;
					}
				}
			}
			if(n%2)ew++;
			else ns++;
			at=n;
		}
		if(ew>6)printf("EW %d\n",ew-6);
		else printf("NS %d\n",ns-6);
	}
}