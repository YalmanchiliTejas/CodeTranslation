#include <iostream>
#include <cmath>


int main(void){

	int priceA, priceB, priceAB;
	std::cin >> priceA >> priceB >> priceAB;

	int reqA, reqB;
	std::cin >> reqA >> reqB;

	long long cost = 0;

	// ABピザのことは考えずに必要数買う
	cost += priceA * reqA;
	cost += priceB * reqB;

	// AB < A + B なら重複しない分だけ買う
	if(priceAB * 2 < (priceA + priceB)){

		int num = (reqA < reqB) ? reqA : reqB;
		int diff = (priceA + priceB) - priceAB * 2;
		cost -= diff * num;
	}

	// 重複させて買う必要があるかどうか
	int overNum = std::abs(reqA - reqB);
	if( (reqA > reqB) && (priceAB * 2 < priceA) ){

		cost -= overNum * (priceA - priceAB * 2);
	}
	else if( (reqB > reqA) && (priceAB * 2 < priceB) ){

		cost -= overNum * (priceB - priceAB * 2);
	}

	std::cout << cost << std::endl;

	return 0;
}