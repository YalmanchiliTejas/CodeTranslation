#include <iostream>

using namespace std;

int main(){
	
	int r, g, b;
	int soma = 0;
	int i=0;
	
	cin >> r >> g >> b;
	
	while (i < r){
		soma = soma + 100;
		i++;
	}
	
	i = 0;
	while (i < g){
		soma = soma + 10;
		i++;
	}
	
	i = 0;
	
	while (i < b){
		soma = soma + 1;
		i++;
	}

	if(soma%4 == 0){
		cout << "YES";
	}else{
		cout << "NO";
	}
	
	return 0;
}