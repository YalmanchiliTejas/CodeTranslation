#include <iostream>
using namespace std;
 
int main(void)
{
	int N;
	int count = 1;
	cin >> N;
	int highest;
	cin >> highest;
	for (int i = 1; i < N; i++) {
		int H;
		cin >> H;
		if (highest <= H) {
			count++;
			highest = H;
		}
 
	}
	cout << count << endl;
 
	return 0;
}