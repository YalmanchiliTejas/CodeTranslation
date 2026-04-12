#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	while(true){
		cin >> N;
		if(N==0){return 0;}

		int* x = new int[N];
		int sum=0;

		for(int i=0; i<N; i++){
			cin >> x[i];
			sum += x[i]; 
		}
		int* x_max = max_element(x,x+N);
		int* x_min = min_element(x,x+N);

		cout << (sum - *x_max - *x_min)/(N-2) << endl;

		delete[] x;
	}
}