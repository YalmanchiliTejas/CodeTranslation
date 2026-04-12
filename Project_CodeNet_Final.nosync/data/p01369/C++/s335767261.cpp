
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);

	//0なら左手、1なら右手
	int ch[] = {
	//	a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
		0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0
	};

	while(1) {
		string s;
		int flg, ans = 0;

		cin >> s;
		if(s == "#") break;
		
		flg = ch[s.at(0) - 'a'];
		for(int i = 0; i < s.length(); i++) {
			int tmp = s.at(i) - 'a';
			if(flg != ch[tmp]) ans ++;
			flg = ch[tmp];
		}
		cout << ans << endl;

	}

	//while(1){}
	return 0;
}