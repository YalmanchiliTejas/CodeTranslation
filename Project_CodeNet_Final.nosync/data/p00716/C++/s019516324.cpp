//#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
//#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
using namespace std;

int main(void){

	int m;
	cin >> m;
	while (m--){
		int money, year, n;
		int max_money = 0;
		scanf("%d%d%d", &money, &year, &n);
		for (int j = 0; j < n; j++){
			int way, commission;
			double r;
			scanf("%d%lf%d", &way, &r, &commission);
			int buff = money;
			if (way == 1){
				for (int k = 0; k < year; k++){
					buff = buff + r * buff - commission;
				}
			}
			else{
				int buff2 = 0;
				for (int k = 0; k < year; k++){
					buff2 += r * buff;
					buff -= commission;
				}
				buff = buff + buff2;
			}
			max_money = max(buff, max_money);
		}
		cout << max_money << endl;
	}

	return 0;
}