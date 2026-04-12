#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;

	cin >> n;

	while(n != 0){
		int point[1005];
		int max = 0, min = 0;

		for(int i=0; i<n; i++){
			cin >> point[i];
		}

		for(int i=1; i<n; i++){
			if(point[max] < point[i])
				max = i;
			else if(point[i] < point[min] )
				min = i;
		}

		point[max] = 0;
		point[min] = 0;

		int sum = 0;

		for(int i=0; i<n; i++)
			sum += point[i];

		//cout << sum << endl;

		cout << sum/(n-2) << endl;

		cin >> n;
	}

	return 0;
}