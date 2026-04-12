#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n, cou = 0, N = 5, E = 3, W = 4, S = 2, U = 1, D = 6,A=0;
	char c[30] = { 0 };
	while (1){
		N = 5, E = 3, W = 4, S = 2, U = 1, D = 6;
		cou = 1;
		cin >> n;
		if (n == 0){
			break;
		}
		for (int i = 0; i < n; i++){
			cin >> c;
			A = 0;
			if (c[0] == 'N'){
				A = N;
				N = U;
				U = S;
				S = D;
				D = A;
				cou = cou + U;
			}
			else if (c[0] == 'E'){
				A = E;
				E = U;
				U = W;
				W = D;
				D = A;
				cou = cou + U;
			}
			else if (c[0] == 'W'){
				A = W;
				W = U;
				U = E;
				E = D;
				D = A;
				cou = cou + U;
			}
			else if (c[0] == 'S'){
				A = S;
				S = U;
				U = N;
				N = D;
				D = A;
				cou = cou + U;
			}
			else if (c[0] == 'L'){
				A = E;
				E = S;
				S = W;
				W = N;
				N = A;
				cou = cou + U;
			}
			else if (c[0] == 'R'){
				A = S;
				S = E;
				E = N;
				N = W;
				W = A;
				cou = cou + U;
			}
		}
		cout << cou << endl;
	}
	return 0;
}