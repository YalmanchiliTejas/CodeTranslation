#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#define pi 3.14159
using namespace std;

 
int main(){
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		double a, b, money, in, sum, max;
		int y, c, d, n;
		cin >> a >> y >> n;
		double e[100];
		for(int j = 0; j < n; j++) {
			money = a;
			sum = 0;
			cin >> c >> in >> d;
			for(int k = 0; k < y; k++) {
				if(c == 0) {
					b = money * in;
					money -= d;
					sum += floor(b);
				} else {
					b = floor(money * in);
					money = money + b - d;
				}
			}
			if(c == 0) e[j] = money + sum;
			else e[j] = money;
		}
		max = e[0];
		for(int j = 1; j < n; j++) {
			if(max < e[j]) max = e[j];
		}
		cout << (int)max <<endl;
		
	}
  
	return 0;
}