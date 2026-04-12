#include<iostream>

using namespace std;

int main() {

	int N,max,look=1,i;
	int Mount[100];

	cin >> N;
	
	for (i = 0; i < N; i++)
		cin >> Mount[i];

	max = Mount[0];

	for (i = 1; i < N; i++) {
		if (max < Mount[i]) {
			max = Mount[i];
			look = look + 1;
		}
		else if (max == Mount[i])
			look = look+1;
	}

	printf("%d", look);
	 
	return 0;

}