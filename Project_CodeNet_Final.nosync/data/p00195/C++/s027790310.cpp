#include <iostream>
using namespace std;

int main(){

	int s1, s2;

	while (cin >> s1 >> s2 && s1 != 0 && s2 != 0){

		int sum[5];
		int max;
		int num;
		sum[0] = s1 + s2;
		max = sum[0];
		num = 0;
		for (int i = 1; i < 5; i++){
			cin >> s1 >> s2;
			sum[i] = s1 + s2;
			if (max < sum[i]){
				max = sum[i];
				num = i;
			}
		}

		cout << (char)('A' + num) << ' ' << max << endl;
	}
}