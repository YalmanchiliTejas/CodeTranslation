#define _USE_MATH_DEFINES
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<climits>
using namespace std;

int main(){
	int S1, S2;
	while(true){
		int ma_idx, ma_s = 0;
		for(int i = 0; i < 5; i++){
			cin >> S1 >> S2;
			if(S1 == 0 && S2 == 0) return 0;
			if(ma_s < S1 + S2){
				ma_idx = i; ma_s = S1 + S2;
			}
		}
		printf("%c %d\n", 'A' + ma_idx, ma_s );
	}
	return 0;
}