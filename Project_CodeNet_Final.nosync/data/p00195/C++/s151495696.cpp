#include <iostream>
using namespace std;

int main() {
	int a,b;
	int i=0;
	int dt[5];
	while(cin >> a >> b) {
		if (i==0&&a==0&&b==0) break;
		dt[i] = a+b;
		i++;
		if (i==5) {
			int pos = 0;
			int max = dt[0];
			for (int j=0; j<5; j++) {
				if (max < dt[j]) {
					max = dt[j];
					pos = j;
				}
			}
			cout << (char)((int)'A'+pos) << ' ' << max << endl;
			i = 0;
		}
	}
	return 0;
}