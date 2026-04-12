// Tazoe

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while(true){
		int n;
		cin >> n;

		if(n==0)
			break;

		int S[100];

		int sum = 0;

		for(int i=0; i<n; i++){
			cin >> S[i];
			sum += S[i];
		}

		sort(S, S+n);

		cout << (sum-S[0]-S[n-1])/(n-2) << endl;
	}

	return 0;
}