// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

void print(int n, vector< vector<int > > S){
	for (int i = 0; i < S.size(); i++){
		for (int j = 0; j < S.size(); j++){
			printf("%4d", S[i][j]);
		}
		cout << endl;
	}
}

void MagicSquare(int n){
	vector< vector<int > > S(n, vector<int > (n, 0));
	int gyo, retu, nowS=1;
	gyo = (n / 2) + 1;
	retu = (n / 2);
	
	S[gyo][retu] = nowS;
	nowS++;

	while (nowS <= n*n){
		// 右斜め下へ
		gyo++;
		retu++;
		while (1){
			if (gyo == n)	gyo = 0;
			if (retu == n)	retu = 0;
			else if (retu == -1)	retu = n - 1;

			if (S[gyo][retu] == 0)	break;
			else {
				// 左斜め下へ
				gyo++;
				retu--;
			}
		}
		// 格納してnowS++
		S[gyo][retu] = nowS;
		nowS++;
	}
	print(n, S);
}

int main(){
	int n;
	while (cin >> n, n){
		MagicSquare(n);
	}
	return 0;
}