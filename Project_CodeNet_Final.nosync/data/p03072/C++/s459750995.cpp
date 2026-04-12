#include <iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int cnt = 0;
	int max = 0;
	cin >> max;
	cnt++;

	for (int i = 1; i < N; i++){
		int h;
		cin >> h;
		if (h >= max){
			max = h;
			cnt++;
		}
	}

	cout << cnt << endl;
}