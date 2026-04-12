#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	n--;
	int h;
	cin >> h;
	int max = h;
	int cnt = 1;
	while (n--) {
		cin >> h;
		if (h >= max) {
			cnt++;
			max = h;
		}
	}
	cout << cnt << endl;
}