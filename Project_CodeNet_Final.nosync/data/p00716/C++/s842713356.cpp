#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;


int main(){
	int m;
	cin >> m;

	int money, year, n;
	int flag, minus;
	double rate;

	//???????????????????????°???????????????
	for(int i=0 ; i<m ; i++){
		cin >> money;
		cin >> year;
		cin >> n;

		int max=0;

		//?????¨???????????°???????????????
		for(int j=0 ; j<n ; j++){
			cin >> flag;
			cin >> rate;
			cin >> minus;

			int A, B;
			A = money;
			B = 0;

			if(flag==0){
				for(int k=0 ; k<year ; k++){
					B += A * rate;
					A -= minus;
				}
				if(max < (A+B)) max = A+B;
			}else if(flag == 1){
				for(int k=0 ; k<year ; k++){
					B = A * rate;
					A = A + B - minus;
				}
				if(max < A) max = A;
			}
		}
		cout << max << endl;
	}
	return 0;
}