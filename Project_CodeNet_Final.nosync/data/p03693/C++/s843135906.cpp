#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main() {

	ll();

	int r, g , b,sum=0;
	cin >> r >> g >> b;
	r *= 100;
	g *= 10;
	sum = r + g + b;
	if (sum % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

		

}