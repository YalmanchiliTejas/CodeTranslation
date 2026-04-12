#include <iostream> 
#include <stdio.h>
#include <string>
using namespace std;
#define MAX_N 21
int main() {
	int n;
	cin >> n;
	int h[MAX_N];
	for (int i(0);i < n;i++){
		cin >> h[i];
	}
	int cnt(0),a(0);
	for (int i(0);i < n; i++){
		a = 0;
		for (int k(0);k < i;k++){
			if (h[k] > h[i]) {
				a = 1;
			}
		}
		if (a == 0){
			cnt += 1;
		}
	}
	cout << cnt;
    return 0;
 }