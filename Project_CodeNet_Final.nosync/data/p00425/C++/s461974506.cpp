
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


//
int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);
	int dice[6][4] = {
		{5,3,2,4},	//表が1
		{1,3,6,4},	//表が2
		{1,6,2,5},	//表が3
		{5,1,2,6},	//表が4
		{6,3,1,4},	//表が5
		{2,3,5,4}	//表が6
	};

	while(1){
		int top = 1;
		int tmp = 0;
		int ans = 1;
		int n = 0;
		int fr = 2,ri = 3;
		string dir;
		cin >> n;

		
		if(n == 0) break;
		

		for(int i = 0; i < n; i++) {
			cin >> dir;
			if(dir == "North") {
				tmp = top;
				top = fr;
				fr = 7 - tmp;
			} else if(dir == "East") {
				tmp = ri;
				ri = top;
				top = 7 - tmp;
			} else if(dir == "South") {
				tmp = top;
				top = 7 - fr;
				fr = tmp;
			} else if(dir == "West") {
				tmp = ri;
				ri = 7 - top;
				top = tmp;
			} else if(dir == "Right") {
				tmp = fr;
				fr = ri;
				ri = 7 - tmp;
			} else if(dir == "Left") {
				tmp = fr;
				fr = 7 - ri;
				ri = tmp;
			}
			ans += top;
		}
		cout << ans << endl;

	}

	//while(1){}
	return 0;
}