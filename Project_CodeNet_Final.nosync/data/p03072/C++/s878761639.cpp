#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_great_ocean_view(void) {
	int n;
	int* h;
	cin >> n;
	h = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) cin >> h[i];

	int cnt = 1;

	for (int i = 1; i < n; i++) {
		bool higher_detect = false;
		for (int j = 0; j < i; j++) {
			if (h[i] < h[j]) {
				higher_detect = true;
				break;
			}
		}
		if (!higher_detect)cnt++;
	}

	cout << cnt << endl;
}

int main()
{
    b_great_ocean_view();

    return 0;
}