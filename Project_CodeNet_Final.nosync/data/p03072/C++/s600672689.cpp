#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, i;
	int count = 0;
	int max = 0;
	int h[100];

	cin >> n;

	for(i = 0; i < n; i++){
		cin >> h[i];
	}

	max = h[0];
	count = 0;
	for(i = 0; i < n; i++){
		if(max <= h[i]){
			max = h[i];
			count++;
		}
	}

	cout << count << endl;

	return 0;
}