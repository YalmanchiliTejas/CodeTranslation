#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)

int x, y, z;
int main()
{
	cin >> x >> y >> z;
	
	int cnt = 0;
	x -= z;
	while (x - y - z >= 0) {
		x -= y;
		x -= z;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}