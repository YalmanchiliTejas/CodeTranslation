#include<iostream>
using namespace std;
int N,S;

int main() {
	while (cin >> N && N>0) { // By while (), adopt the form of std in 
		int sum = 0;
		int max = 0;
		int min = 0;
		for (int i=0; i<N; i++) {
			cin >> S;
			if (i==0) min = S; // initialize min
			sum += S; // calculate sum
			if (max < S) max = S; // search max
			if (min > S) min = S; // search min
		}
		int ans;
		ans = (sum-max-min)/(N-2);
		cout << ans << endl;
	}
	return 0;
}
