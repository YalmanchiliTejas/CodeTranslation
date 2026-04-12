#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int x, y, count = 1;
	cin >> x;
	for (int i = 1 ; i < N ; i++){
		cin >> y;
		if (y >= x){
			count++;
			x = y;
		}
	}
	cout << count;
	return 0;
}

