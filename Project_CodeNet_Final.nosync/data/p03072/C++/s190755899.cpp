#include <iostream>
using namespace std;

int main()
{
	int N, H[100], flag, count = 1;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	
	for (int i = 1; i < N; i++) {
		flag = 1;
		
		for (int j = 0; j < i; j++) {
			if (H[j] > H[i]) {
				//海を眺められない
				flag = 0;
				break;
			}
		}
		
		if (flag) {
			//海を眺められる
			count++;
		}
	}
	
	cout << count << endl;
}
