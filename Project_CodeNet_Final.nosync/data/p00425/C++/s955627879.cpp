#include <iostream>

int main(void){
	char mei[64];
	int n;

	while(true){
		std::cin >> n;
		if(!n) break;

		int dC = 1;
		int dN = 5;
		int dS = 2;
		int dE = 3;
		int dW = 4;
		int dX = 6;

		int rNS = 0;
		int rEW = 0;
		int rRL = 0;
		int sum = 1;

		for(int i=0; i<n; i++){
			std::cin >> mei;
			switch(mei[0]){
			case 'N':{
				int _dX = dX;
				dX = dN;
				dN = dC;
				dC = dS;
				dS = _dX;
			}break;

			case 'S':{
				int _dX = dX;
				dX = dS;
				dS = dC;
				dC = dN;
				dN = _dX;
			}break;

			case 'E':{
				int _dX = dX;
				dX = dE;
				dE = dC;
				dC = dW;
				dW = _dX;
			}break;

			case 'W':{
				int _dX = dX;
				dX = dW;
				dW = dC;
				dC = dE;
				dE = _dX;
			}break;

			case 'R':{
				int _dN = dN;
				dN = dW;
				dW = dS;
				dS = dE;
				dE = _dN;
			}break;

			case 'L':{
				int _dN = dN;
				dN = dE;
				dE = dS;
				dS = dW;
				dW = _dN;
			}break;

			}

			sum += dC;

		}

		std::cout << sum << '\n';

	}

	return 0;
};