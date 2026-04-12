#include <bits/stdc++.h>
using namespace std;

char s[10][10];

int main(){
	int h, w, cnt1, cnt2;
	scanf("%d %d",&h,&w);
	for (int i = 1; i <= h; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			if (s[i][j] != '#' || (i == 1 && j == 1) || (i == h && j == w)) continue;
			cnt1 = cnt2 = 0;
			if (i > 1 && s[i - 1][j] == '#') cnt1++;
			if (j > 1 && s[i][j - 1] == '#') cnt1++;
			if (i < h && s[i + 1][j] == '#') cnt2++;
			if (j < w && s[i][j + 1] == '#') cnt2++;
			if (cnt1 != 1 || cnt2 != 1){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	cnt2 = 0;
	if (s[2][1] == '#') cnt2++;
	if (s[1][2] == '#') cnt2++;
	if (s[1][1] != '#' || cnt2 != 1){
		printf("Impossible\n");
		return 0;
	}
	cnt1 = 0;
	if (s[h - 1][w] == '#') cnt1++;
	if (s[h][w - 1] == '#') cnt1++;
	if (s[h][w] != '#' || cnt1 != 1){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	return 0;
} 