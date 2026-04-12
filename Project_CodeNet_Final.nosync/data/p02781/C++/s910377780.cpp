#include <bits/stdc++.h>
 
using namespace std;

string n;

int memo[150][5][3];

int solve(int index, int k, int livre) {
	int op1 = 0;
	int op2 = 0;
	int op3 = 0;

	if(index == n.size()){
		if(k == 0) return 1;
		return 0;
	}

	if(memo[index][k][livre] != -1) {
		return memo[index][k][livre];
	}
	
	if(livre) {
		// colocar 0 nessa posicao
		op1 = solve(index+1, k, livre);
		
		if(k > 0) {
			// colocar qualquer numero entre 1 e 9
			op2 = solve(index+1, k-1, livre)*9;
		}
	} else {
		// livre == false
		int digito = n[index] - '0';
		if(digito == 0) {
			// so tenho uma opcao
			op1 = solve(index+1, k, livre);
		} else {
			if(k > 0) {
				// libero colocando qualquer numero menor que eu menos o 0
				op1 = solve(index+1, k-1, 1)*(digito-1);

				// coloco meu proprio numero e nao libero
				op2 = solve(index+1, k-1, livre);
			} 
			// coloca 0 e libera
			op3 = solve(index+1, k, 1);
		}
	}

	return memo[index][k][livre] = op1 + op2 + op3;
}

int main() {
	int k;
	cin >> n >> k;

	for(int i = 0; i < 150; i++) {
		for(int j = 0; j < 5; j++) {
			for(int l = 0; l < 3; l++) {
				memo[i][j][l] = -1;
			}
		}
	}

	// index, quantidade de 0 que falta, livre
	printf("%d\n", solve(0, k, 0));

	return 0;
}