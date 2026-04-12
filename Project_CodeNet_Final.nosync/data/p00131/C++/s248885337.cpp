#include <iostream>
#include <string.h>
using namespace std;
int dx[]={-1,0,1,0,0};
int dy[]={0,-1,0,1,0};

int main() {
	int n ; cin >> n ;
	while(n--){
		int field[10][10];
		for(int i=0;i<10;i++) for(int j=0;j<10;j++) cin >> field[i][j];
		int tmp_ans[10][10]={0};
		int tmp_field[10][10];
		for(int i=0;i<1<<10;i++){
			bool failed=false;
			memset(tmp_ans,0,sizeof(tmp_ans));
			memcpy(tmp_field,field,sizeof(field));
			for(int j=0;j<10;j++) tmp_ans[0][10-1-j]= i>>j & 1;
			for(int j=0;j<10;j++){
				if(tmp_ans[0][j]){
					for(int m=0;m<=4;m++)
						if(0<=j+dx[m] && j+dx[m]<10 && 0<=dy[m] ) (tmp_field[dy[m]][j+dx[m]])^=1;
				}
			}
			for(int l=1;l<10;l++){
				for(int k=0;k<10;k++){
					if(tmp_field[l-1][k]){
						tmp_ans[l][k]=true;
						for(int m=0;m<=4;m++)
							if(0<=k+dx[m] && k+dx[m]<10 && 0<=l+dy[m] && l+dy[m]<10) tmp_field[l+dy[m]][k+dx[m]]^=1;
					}
				}
			}
			for(int j=0;j<10;j++) if(tmp_field[9][j]) failed=true;
			if(!failed) break;
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++) {if(j) cout << ' ' ; cout << tmp_ans[i][j] ;}
			cout << '\n' ;	
		}
	}
}