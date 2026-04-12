#include<iostream>
using namespace std;
int main() {
	int date[55],ne[55],n,ans,kazu[55];
	n = 0;
	ans = 1;
	for (int i = 1; i <= 44; i++) {
		kazu[i] = 0;
	}
	for (int i = 1; i <= 12; i++) {
		cin >> date[i];
		for (int z = 1; z <= n; z++) {
			if (ne[z] == date[i]) {
				kazu[z] = kazu[z] + 1;
				goto a;
			}
		}
		n = n + 1;
		ne[n] = date[i];
		kazu[n] = 1;
	a:;
	}
	if (n <= 3) {
		for (int i = 1; i <= n; i++) {
			if (kazu[i] % 4 != 0) {
				goto b;
			}
		}
	}
	else {
	b:;
		ans = 0;
	}
	if (ans) {
		cout << "yes"<<endl;
	}
	else {
		cout << "no" << endl;
	}
}
