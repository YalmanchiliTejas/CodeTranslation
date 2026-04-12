#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

char trump,led;

int f(int rank,char suit){
	if(suit==trump) return 100*rank;
	if(suit==led)   return rank;
	return 0;
}

int main(){
	int RANK[128];
	RANK['2']=2;
	RANK['3']=3;
	RANK['4']=4;
	RANK['5']=5;
	RANK['6']=6;
	RANK['7']=7;
	RANK['8']=8;
	RANK['9']=9;
	RANK['T']=10;
	RANK['J']=11;
	RANK['Q']=12;
	RANK['K']=13;
	RANK['A']=77;

	for(;scanf("%c ",&trump),trump!='#';){
		int rank[4][13];
		char suit[4][13];
		rep(i,4) rep(j,13) {
			char c; scanf("%c%c ",&c,suit[i]+j);
			rank[i][j]=RANK[c];
		}

		int ans[2]={},dealer=0;
		rep(j,13){
			int i=dealer,i_opt=0;
			led=suit[dealer][j];
			rep(t,4){
				if(f(rank[i][j],suit[i][j])>f(rank[i_opt][j],suit[i_opt][j])) i_opt=i;
				i=(i+1)%4;
			}

			ans[i_opt%2]++;
			dealer=i_opt;
		}

		if(ans[0]>ans[1]) printf("NS %d\n",ans[0]-6);
		else              printf("EW %d\n",ans[1]-6);
	}

	return 0;
}