#include<bits/stdc++.h>

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	int a[h][w];
	for(int i=0; i<h; i++){
		char s[w+1];
		scanf("%s", s);
		for(int j=0; j<w; j++) a[i][j] = (s[j]=='#');
	}

	bool skipr[h], skipc[w];
	memset(skipr, 0, sizeof(skipr));
	memset(skipc, 0, sizeof(skipc));

	for(int i=0; i<h; i++){
		bool skip = true;
		for(int j=0; j<w; j++){
			if(a[i][j]==1) skip = false;
		}
		if(skip) skipr[i] = true;
	}

	for(int j=0; j<w; j++){
		bool skip = true;
		for(int i=0; i<h; i++){
			if(a[i][j]==1) skip = false;
		}
		if(skip) skipc[j] = true;
	}
	
	for(int i=0; i<h; i++) if(!skipr[i]) {
		for(int j=0; j<w; j++) if(!skipc[j]) {
			if(a[i][j]) putchar('#');
			else putchar('.');
		}
		putchar('\n');
	}
	return 0;		
}
