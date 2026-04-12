#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,c,x,y;
	cin >> a >> b >> c >> x>> y;

	int maxab = max(x * 2, y * 2);

	int price;
	int minprice=2000000000;
	for (int i = 0; i <= maxab; i++) {
		price = c * i + max((x - (int)i / 2)*a,0) + max((y - (int)i / 2)*b,0);
		minprice = min(minprice, price);
	}
	cout << minprice << endl;

}