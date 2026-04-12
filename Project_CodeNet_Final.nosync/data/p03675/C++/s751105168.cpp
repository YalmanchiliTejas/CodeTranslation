#include <iostream>
using namespace std;


int a[200001];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];

	if ((N%2)==1) {
		for (int i = N; i > 0; i-=2) {
			cout << a[i] << " ";
		}
		for (int i = 2; i <= N; i+=2) {
			cout << a[i] << " ";
		}
	} else {
		for (int i = N; i > 0; i-=2) {
			cout << a[i] << " ";
		}
		for (int i = 1; i <= N; i+=2) {
			cout << a[i] << " ";
		}
	}
	cout << endl;

	return 0;
}