#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
 
int main() {
	int N;
	cin >> N;
	char a[N];
	cin >> a;
	int K;
	cin >> K;
	for (int i = 0; i < N; i++) {
		if (a[i] != a[K-1]) {
			a[i] = '*';
		}
	}
	cout << a << endl;
}