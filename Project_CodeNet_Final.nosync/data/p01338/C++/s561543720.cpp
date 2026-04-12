#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=1<<29;
int memo[6][4][4][4][4];

int main(){
	const int score[]={0,60,70,80};

	int t;	scanf("%d",&t);
	while(t--){
		int field[5][5];
		for(int i=0;i<5;i++)for(int j=0;j<5;j++)	scanf("%d",field[i]+j);

		for(int i=0;i<4;i++)for(int j=0;j<4;j++)for(int k=0;k<4;k++)for(int l=0;l<4;l++)
			memo[0][i][j][k][l]=-inf;
		memo[0][0][0][0][0]=0;

		for(int row=1;row<=5;row++){
			for(int i=0;i<4;i++)for(int j=0;j<4;j++)for(int k=0;k<4;k++)for(int l=0;l<4;l++){
				memo[row][i][j][k][l]=-inf;
				for(int p=0;p<4;p++)for(int q=0;q<4;q++)for(int r=0;r<4;r++)for(int s=0;s<4;s++){
					int cnt[5]={};
					cnt[0]=i+p;
					cnt[1]=i+j+p+q;
					cnt[2]=j+k+q+r;
					cnt[3]=k+l+r+s;
					cnt[4]=l+s;
					int rowscore=0;
					for(int m=0;m<5;m++){
						if(field[row-1][m]>0)	rowscore+=score[(field[row-1][m]-1+cnt[m])&3];
					}
					memo[row][i][j][k][l]=max(memo[row][i][j][k][l],
						memo[row-1][p][q][r][s]+rowscore);
				}
			}
		}

		printf("%d\n",memo[5][0][0][0][0]);
	}

	return 0;
}