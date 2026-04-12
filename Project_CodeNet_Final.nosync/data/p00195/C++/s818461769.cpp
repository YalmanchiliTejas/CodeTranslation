#include <iostream>
#include <algorithm>

using namespace std;

struct Shop {
	char name;
	int sell[2];
	int total;
};

bool compare(Shop i, Shop j) {
	return (i.total < j.total);
}

int main() {
	
	Shop shop[5];
	bool test = false;

	while (true) {

		shop[0].name = 'A';
		for (int i = 0; i < 5; i++) {
			cin >> shop[i].sell[0] >> shop[i].sell[1];
			if (shop[0].sell[0] == 0 && shop[0].sell[1] == 0 && i == 0) {
				test = true;
				break;
			}
			shop[i].total = shop[i].sell[0] + shop[i].sell[1];
			shop[i].name = 'A' + i;

		}
		if (test)
			break;
		sort(shop, shop + 5, compare);
		cout << shop[4].name << " " << shop[4].total << "\n";

	}
	
	return 0;

}





