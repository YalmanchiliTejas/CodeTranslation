#include <iostream>
#include <climits>
using namespace std;

int main(void){
	int n,m,max,min,answer;
	while(1){
		cin >> n;
		max = 0;
		min = INT_MAX;
		answer = 0;
		if (!n) break;
		for (int i=0;i< n;i++){
			cin >> m;
			if (m > max) max = m;
			if (m < min) min = m;
			answer += m;

		}
		cout << (answer-max-min)/(n-2) << endl;

	}

	return 0;
}