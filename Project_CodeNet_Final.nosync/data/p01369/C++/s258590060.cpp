#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	int hand=2;
	int hands = 2;
	int counts = 0;
	int i;
	string side;
	while (1) {
		cin >> side;
		if (side == "#") { break; }
		for(i = 0; side[i] != '\0'; i++ ) {
			if (side[i] == 'y'|| side[i] == 'h'|| side[i] == 'n'
				|| side[i] == 'u'|| side[i] == 'j'|| side[i] == 'm'
				|| side[i] == 'i'|| side[i] == 'k'|| side[i] == 'o'
				|| side[i] == 'l'|| side[i] == 'p') {			hand = 0;
			}
			else { hand = 1; }
			if (hand != hands) { counts += 1; }
			hands = hand; }
		cout << counts - 1<<endl;
		counts = 0;
		hands = 2;
}
	return 0;}