#include <iostream>
#include <vector>

using namespace std;


int main()
{

	int n;
	cin >> n;
	int max = -1;
	int answer = 0;
	int h;

	for (int i = 0; i < n; i++) {
		cin >> h;
		if (h >= max) {
			answer++;
			max = h;
		}
	}

	cout << answer << endl;

    return 0;
}
