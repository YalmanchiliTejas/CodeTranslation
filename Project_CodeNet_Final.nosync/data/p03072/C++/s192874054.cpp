#include <iostream>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int qtd_inns, altura_inn, maior_altura = 0, visao_oceano = 0;

	cin >> qtd_inns;

	for(int i=1; i<=qtd_inns; i++){
		cin >> altura_inn;

		if(altura_inn >= maior_altura){
			maior_altura = altura_inn;
			visao_oceano++;
		} 
	}

	cout << visao_oceano << endl;

	return 0;
}