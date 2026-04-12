// AOJ 2406

#include <iostream>
using namespace std;

int main(void)
{
	int n, t, e;
	int data[100];
	cin >> n >> t >> e;
	int left = (t - e), right = (t + e);
	
	for (int i = 0; i < n; i++) cin >> data[i];
	
	for (int i = left; i <= right; i++){
		for (int j = 0; j < n; j++){
			if (i % data[j] == 0){
				cout << j + 1 << endl;
				goto END;
			}
		}
	}
	
	cout << "-1" << endl;
	END: ;
	
	return 0;
}