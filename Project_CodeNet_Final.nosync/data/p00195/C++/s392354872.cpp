#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	bool check = false;

	while (1){
		int max = 0;
		int num;

		for (int i = 0; i < 5; i++){
			cin >> a >> b;
			if (a == 0 && b == 0){
				check = true;
				break;
			}

			int sum = a + b;

			if (sum > max){
				max = sum;
				num = i;
			}
		}

		if (check){
			break;
		}

		printf("%c %d\n", num + 0x41, max);
	}

	return (0);
}