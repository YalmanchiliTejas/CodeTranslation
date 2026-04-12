#include <iostream>
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
	
	int x, dev=0,s=0;
	cin >> x;
	dev = x / 15;
	x *= 800;
	while (dev)
	{
		x -= 200;
		dev--;
	}
	cout << x << endl;

}