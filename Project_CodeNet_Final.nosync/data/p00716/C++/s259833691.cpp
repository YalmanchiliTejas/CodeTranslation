#include <iostream>
using namespace std;

int investment = 0;
double rate = 0;
int commision = 0;

int simple(int y){
	int wage = investment;
	int InterestTotal = 0;
	
	for (int i = 0; i < y; i++){
		InterestTotal += wage * rate;
		wage -= commision;
	}
	wage += InterestTotal;
	return wage;
}

int compound(int y){
	int wage = investment;

	for (int i = 0; i < y; i++){
		wage = (wage * (1+rate)) - commision;
	}

	return wage;
}

int main(){
	int m; //????????????????????°
	int Max = 0;
	cin >> m;

	for (int i = 0; i < m; i++){
		int y, n; //?????¨??´??°????¨??????°
		cin >> investment >> y >> n;

		for (int j = 0; j < n; j++){
			int type; //??????:0, ??????:1
			cin >> type >> rate >> commision;
			int tmp;

			if (type == 0){
				tmp = simple(y);
				if (Max < tmp){
					Max = tmp;
				}
			}
			else{
				tmp = compound(y);
				if (Max < tmp){
					Max = tmp;
				}
			}
		}
		cout << Max << endl;
		Max = 0;
	}
	return 0;
}