#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int MaxN = 1e5 + 5;
int n;
char s[MaxN];
int ans[MaxN];
bool flag;
void search(int x, int y){
	int p = 0;
	ans[++p] = x;
	ans[++p] = y;
	for(int i = 2; i <= n; i++){
		if(ans[i] == 1){
			if(s[i] == 'o')
				ans[i + 1] = ans[i - 1];
			else if(s[i] == 'x')
				ans[i + 1] = -ans[i - 1];
		}
		else if(ans[i] == -1){
			if(s[i] == 'o')
				ans[i + 1] = -ans[i - 1];
			else if(s[i] == 'x')
				ans[i + 1] = ans[i - 1];
		}
	}
	if(ans[1] == ans[1 + n]){
		if(ans[1] == 1){
			if(s[1] == 'o' && ans[2] == ans[n]) flag = true;
			else if(s[1] == 'x' && ans[2] != ans[n]) flag = true;
		}
		else if(ans[1] == -1){
			if(s[1] == 'o' && ans[2] != ans[n]) flag = true;
			else if(s[1] == 'x' && ans[2] == ans[n]) flag  = true;
		}
	}	
}
int main(){
	while(~scanf("%d", &n)){
		scanf("%s", s + 1);
		for(int i = -1; i <= 1; i++){
			for(int j = -1; j <= 1; j++){
				if(i == 0 || j == 0) continue;
				if(!flag) search(i, j);
			}
		}
		if(!flag) printf("-1\n");
		else{
			for(int i = 1; i <= n; i++)
				if(ans[i] == 1) printf("S");
				else if(ans[i] == -1) printf("W");
			printf("\n");
		}
	memset(ans, 0, sizeof(ans));
	memset(s, 0, sizeof(s));
	flag = false;
	}
	return 0;
}
				
