#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, num = 0, max, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (i == 0) {
			max = temp;
			num++;
		}
		else if (max <= temp) {
			max = temp;
			num++;
		}
		else;
	}
	cout << num << endl;
}
