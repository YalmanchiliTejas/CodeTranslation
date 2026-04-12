#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

int cnt = 0, n;

struct st {
	int ab[10][10];
};
struct st stt;

struct sttyo {
	bool tyo[10];
};
sttyo sss;

int func(int in, st tt, sttyo ty) {
//int func(int in, int  *ab, bool  *tyo) {
	/*
	for (int i = 0; i < 10; i++) cout << i << " ";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << ab[i][j] << " ";
		}
		cout << endl;
	}
	*/

	//cout << "in->" << in << endl;
	ty.tyo[in] = true;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (ty.tyo[i] == false) flag = true;
	}
	if (flag == false) {
		cnt++;
		//cout << "cnt->" << cnt << endl;
		//cout  << cnt << endl;
		return 0;
	}

	for (int i = 1; i < 10; i++) {
		if (i == in) continue;
		if (tt.ab[in][i] == 0 && ty.tyo[i]==false) {
		//if (ab[in][i] == 0) {
			tt.ab[in][i] = 1;
			func(i, tt, ty);
		}
		//tyo[in] = true;
	}
	//tyo[in] = true;

	//return 0;
}

int main() {
	int i, j, k;
	int m; //ab[10][10];
	bool tyo[10];

	//fill((int*)ab, (int*)(ab+10), -1);
	fill(tyo, tyo + 10, false);

	cin >> n >> m;

	
	

	fill((int*)stt.ab, (int*)(stt.ab + 10), -1);

	int a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		stt.ab[a][b] = 0;
		stt.ab[b][a] = 0;
	}


	func(1, stt, sss);


	cout << cnt << endl;




	getchar();
	getchar();
	return 0;
}