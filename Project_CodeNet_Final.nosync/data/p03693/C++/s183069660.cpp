#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
	  



	int r, g, b; cin >> r >> g >> b;
	int sum = ((r % 10)*10 + g % 10 )*10+ b % 10;
	if (sum % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


		return 0;
	
}
