#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cstdlib>
#include <math.h>
#include<algorithm>
using namespace std;


int main(int argc,char** argv)
{

	int a,b;
	cin >> a >> b;
	char c[a][b];
	int gyou[a];
	int retu[b];

	//初期化
	for(int i = 0; i < a; i++){
		gyou[i] = 0;
	}
	for(int i = 0; i < b; i++){
		retu[i] = 0;
	}

	//代入＆値の確認
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cin >> c[i][j];
			if(c[i][j] == '.'){
				gyou[i]++;
				retu[j]++;
			}
		}
	}

	int f=0;
	for(int k = 0; k < a; k++){
		for(int m = 0; m < b; m++){
			if (gyou[k] == b || retu[m] == a){
				//
			}
			else{
				cout << c[k][m];
				f++;
			}
		}
		if(f!=0){
			cout << endl;
		}
		f=0;
	}

	return 0;
}