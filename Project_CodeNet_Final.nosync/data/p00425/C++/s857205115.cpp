#include <cstdio>

int main(){
	int n, c, d[6], t;
	char s[10];
	while(scanf("%d", &n), n != 0){
		for(int i = 0;i < 6;i++)d[i] = i + 1;
		t = 1;
		for(int i = 0;i < n;i++){
			scanf("%s", s);
			if(s[0] == 'N'){
				c = d[0];
				d[0] = d[1];
				d[1] = d[5];
				d[5] = d[4];
				d[4] = c;
			}
			if(s[0] == 'E'){
				c = d[0];
				d[0] = d[3];
				d[3] = d[5];
				d[5] = d[2];
				d[2] = c;
			}
			if(s[0] == 'W'){
				c = d[0];
				d[0] = d[2];
				d[2] = d[5];
				d[5] = d[3];
				d[3] = c;
			}
			if(s[0] == 'S'){
				c = d[0];
				d[0] = d[4];
				d[4] = d[5];
				d[5] = d[1];
				d[1] = c;
			}
			if(s[0] == 'R'){
				c = d[1];
				d[1] = d[2];
				d[2] = d[4];
				d[4] = d[3];
				d[3] = c;
			}
			if(s[0] == 'L'){
				c = d[1];
				d[1] = d[3];
				d[3] = d[4];
				d[4] = d[2];
				d[2] = c;
			}
			t += d[0];
		}
		printf("%d\n", t);
	}
	return 0;
}