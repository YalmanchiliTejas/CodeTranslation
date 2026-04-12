#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	
	int n;
	
	while(cin >> n && n!=0) {
		
		int *A;
		int sum = 0;
		
		A = new int[n];
		
		for(int i=0;i<n;i++)
			cin >> A[i];
		
		sort(A, A+n);
		
		for(int i=1;i<n-1;i++)
			sum += A[i];
		
		cout << sum / (n - 2) << "\n";
		delete [] A;
		A = NULL;
	}

	return 0;
}

