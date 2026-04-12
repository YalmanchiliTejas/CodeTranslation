//AtCoder Beginner Contest 000 A問題
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	bool yes = true;
	int h,w;
	scanf("%d%d", &h,&w);
	char a[h][w];
	for(int i=0;i<h;i++){
		scanf("%s", a[i]);
	}
	int stend[h][2];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j] == '#'){
				stend[i][0] = j;
				break;
			}
		}
		for(int j=w-1;j>=0;j--){
			if(a[i][j] == '#'){
				stend[i][1] = j;
				break;
			}
		}
	}
	for(int i=0;i<h-1;i++){
		if(stend[i][1] != stend[i+1][0]){
			yes = false;
		}
	}
	if(yes) printf("Possible\n");
	else printf("Impossible\n");
}