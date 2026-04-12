#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;



int main(){

	
	int N, T, E;
	cin >> N >> T >> E;

	int min = T - E , max = T + E;

	int b = -1;
	for (int i = 0; i < N; i++){
		int n;
		cin >> n;
		for (int j = min; j <= max; j++){
			if (j%n == 0){
				b = i + 1;
			}
		}

		if (b != -1)break;
		
	}
	cout << b << endl;
	return 0;

}