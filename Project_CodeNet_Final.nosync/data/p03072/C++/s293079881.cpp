#include <bits/stdc++.h>
using namespace std;


int main()
{
  	int N;
	cin >> N;
	int H[N];
	int count;
	int current_height;
	count = 1;
	for (int i=0;i<N;i++){
		cin >> H[i];
	}
	current_height = H[0];
	for (int i=1;i<N;i++){
		if (H[i] >= current_height){
			count += 1;
			current_height = H[i];
		}
	}		
	cout << count << endl;

	return 0;
}