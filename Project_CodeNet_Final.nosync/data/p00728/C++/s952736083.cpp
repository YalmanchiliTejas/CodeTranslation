#include <iostream>
using namespace std;
int main(){
	int n;
	int max;
	int min;
	int y[20] = { 0 };

	n = 1;
		int j = 0;
		while (1){
			
			cin >> n;
			if (n == 0) break;
			max = 0;
			min = 1000;
			for (int i = 0; i < n; i++){
				int x[1000] = { 0 };
				cin >> x[i];

				if (max < x[i]) max = x[i];
				if (min > x[i]) min = x[i];
				y[j] += x[i];
			}
			y[j] = y[j]-max - min;
			y[j] = y[j] / (n - 2);
			j++;
		}
	for (int k = 0; k < j; k++){
		cout << y[k]<< endl ;
	}
	return 0;
}