#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<numeric>
#include<iomanip>

using namespace std;

int main() {
	int n; cin >> n;
	vector<long long int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<long long int>ans1(n / 2), ans2(n / 2);
	long long int tmp = 0;
	unsigned long long int sum1 = 0;
	unsigned long long int sum2 = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			ans1[i]= a[n - i - 1];
			ans2[i]= a[i];
		}
	}
	else {
		unsigned long long  x = n / 2;
		tmp = a[x];
		for (int i = 0; i < n / 2; i++) {
			ans1[i] = a[n - i - 1];
			ans2[i] = a[i];
		}

	}
	for (int i = 0; i < n/2; i++){
		sum1 += abs(ans1[i] - ans2[i]);
		sum2 += abs(ans1[i] - ans2[i]);
		if (i != n/2 - 1) {
			sum1 += abs(ans2[i] - ans1[i + 1]);
			sum2 += abs(ans1[i] - ans2[i + 1]);
		}
    }
	
	if (tmp != 0) {
		sum1 +=max(abs(tmp - ans1[0]),abs(tmp-ans2[n/2-1]));
		sum2+= max(abs(tmp - ans2[0]), abs(tmp - ans1[n / 2 - 1]));
	}
	if (tmp == 0) {
		if (abs(ans1[n / 2 - 1] - ans2[n / 2 - 1])
			< abs(ans1[0] - ans2[n / 2 - 1])){
			sum1 += -abs(ans1[n / 2 - 1] - ans2[n / 2 - 1])
			+ abs(ans1[0] - ans2[n / 2 - 1]);
	     }if(abs(ans1[n / 2 - 1] - ans2[n / 2 - 1])
			 < abs(ans2[0] - ans1[n / 2 - 1])) {
			 sum2 += -abs(ans1[n / 2 - 1] - ans2[n / 2 - 1])
				 + abs(ans2[0] - ans1[n / 2 - 1]);
		 }


	}
	cout << max(sum1,sum2) << endl;
}



