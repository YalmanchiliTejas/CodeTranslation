#include<bits/stdc++.h>
using namespace std;

char h[1000][1000];
int s[1000],ans1[1000],ans2[1000];

int main(){
	int n,flag = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%s",h[i]);
		s[i] = strlen(h[i]);
	}
	for(int i = 49;i <=74;i++){
		ans2[i] = 10000000;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < s[i];j++){
	    	ans1[h[i][j] - '0']++;
		}
		for(int k = 49;k <= 74;k++){
			ans2[k] = min(ans1[k],ans2[k]);
		}
		memset(ans1,0,sizeof(ans1));
	}
	char p;
	for(int i = 49;i <= 74;i++){
		if(ans2[i] != 0){
			for(int j = 1;j <= ans2[i];j++){
				flag = 1;
				printf("%c",i + '0');
			}
		}
	}
	if(flag == 0) printf("\n");
}
