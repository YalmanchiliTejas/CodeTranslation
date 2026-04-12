# include "iostream"
# include "cstdio"

using namespace std;

const int maxm=100+10; 

int N,W;
bool map[maxm][maxm],Line[maxm],List[maxm]; 
char s[maxm];

int main(){
	register int i,j; 
	scanf("%d%d",&N,&W);
	for(i=1;i<=N;i++){
		scanf("%s",s+1);
		for(j=1;j<=W;j++){
			map[i][j]=(s[j]=='#');
			if(map[i][j]){
				Line[i]=true;
				List[j]=true; 
			} 
		} 
	}
	for(i=1;i<=N;i++){
		if(!Line[i]) continue;
		for(j=1;j<=W;j++){
			if(!List[j]) continue;
			if(map[i][j]){
				putchar('#'); 
			}else{
				putchar('.'); 
			} 
		}putchar('\n'); 
	}
	return 0; 
}