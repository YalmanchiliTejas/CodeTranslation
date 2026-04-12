#include<cstdio>
#include<string>

using namespace std;

int main(void){
	int n;
	while(scanf("%d", &n) && n != 0){
		int dice[6] = {1,2,3,4,5,6};
		int ans = 1;
		int c = 0;
		
		char str[16];
		
		for(int i = 0; i < n; i++){
			int temp;
			
			scanf("%s", str);
			
			if(str[0] == 'N'){
				temp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = temp;
			}else if(str[0] == 'E'){
				temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
			}else if(str[0] == 'W'){
				temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;
			}else if(str[0] == 'S'){
				temp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = temp;
			}else if(str[0] == 'R'){
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[3];
				dice[3] = temp;
			}else if(str[0] == 'L'){
				temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];
				dice[4] = dice[2];
				dice[2] = temp;
			}
			ans += dice[0];
		}
		printf("%d\n",ans);
	}
	return 0;
}