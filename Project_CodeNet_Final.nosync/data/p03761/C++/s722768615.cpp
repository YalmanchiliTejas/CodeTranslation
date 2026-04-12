#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
int n , num[100][200] , ans[200];
char a[100][100];
int main(){
	while(~scanf("%d" , &n)){
		memset(num , 0 , sizeof(num));
		memset(ans , 0 , sizeof(ans));
		for(int i = 1;i <= n;i++){
			scanf("%s" , a[i] + 1);
			for(int j = 1;j <= strlen(a[i] + 1);j++)
				num[i][a[i][j]]++;
		}
		int ok = 0;
		for(char i = 'a';i <= 'z';i++){
			if(num[1][i] != 0){
				ans[i] = num[1][i];
				for(int j = 2;j <= n;j++){
					ans[i] = min(ans[i] , num[j][i]);
				}
				if(ans[i] != 0) ok++;
			}
		}
		if(!ok) printf(" \n");
		else {
			for(char i = 'a';i <= 'z';i++){
				if(ans[i]){
					for(int j = 1;j <= ans[i];j++){
						printf("%c" , i);
					}
				}
			}
			printf("\n");
		}
	}
}