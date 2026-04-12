#include<bits/stdc++.h>
using namespace std;
int h,w;
int cnt;
int main(){
	scanf("%d%d",&h,&w);
	for(int i = 1;i <= h;i++){
		getchar();
		for(int j = 1;j <= w;j++){
			char ch = getchar();
			if(ch == '#') cnt++;
		}
	}
	if(cnt == h + w - 1) printf("Possible");
	else printf("Impossible");
	return 0;
}
