#include <iostream>
using namespace std;

int main() {
	int mealsBought, totalPayed, cashback;
	
	cin >> mealsBought;
	totalPayed = mealsBought * 800;
	cashback = (mealsBought / 15) * 200;
	
	cout << totalPayed - cashback << endl;
}