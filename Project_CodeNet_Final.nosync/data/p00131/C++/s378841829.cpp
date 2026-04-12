#include<cstdio>
#include<cstring>

int n;
int fie[13][13];
int now[13][13];
int res[13][13];

void flip(int x,int y){
	fie[x][y]=1-fie[x][y];
	fie[x][y+1]=1-fie[x][y+1];
	fie[x][y-1]=1-fie[x][y-1];
	fie[x+1][y]=1-fie[x+1][y];
	fie[x-1][y]=1-fie[x-1][y];
}

void check(int x,int y){
	if(y==11){
		int flag=0;
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++)if(fie[j][i]==1)flag=1;
		}
		if(flag==0){
			for(int i=1;i<=10;i++){
				for(int j=1;j<=10;j++)res[j][i]=now[j][i];
			}
		}
		return;
	}
	if(y==1){
		now[x][y]=0;
		if(x<=9)check(x+1,y);
		else check(1,y+1);
		
		flip(x,y);
		now[x][y]=1;
		if(x<=9)check(x+1,y);
		else check(1,y+1);
		flip(x,y);
		
	}else{
		if(fie[x][y-1]==1){
			flip(x,y);
			now[x][y]=1;
			if(x<=9)check(x+1,y);
			else check(1,y+1);
			flip(x,y);
		}else{
			now[x][y]=0;
			if(x<=9)check(x+1,y);
			else check(1,y+1);
		}
	}
}

int main(void){
	scanf("%d",&n);
	for(int kkk=0;kkk<n;kkk++){
		memset(fie,0,sizeof(fie));
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++)scanf("%d",&fie[j][i]);
		}
		memset(now,0,sizeof(now));
		memset(res,-1,sizeof(res));
		check(1,1);
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++)printf("%d%c",res[j][i],j==10?'\n':' ');
		}
	}
	return 0;
}