#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int kazu, score, q = 0, sum = 0, ave;
	//審査員の数を入れる
	while (cin >> kazu) {
		if (kazu == 0)break;
		int *point = new int[kazu];
		while (cin >> score) {
			for (int w = 0; w < q; w++) {
				if (point[w] < score)
					swap(point[w], score);
			}
			point[q] = score;
			q++;
			if (q == kazu)break;
		}
		for (int w = 1; w < q-1; w++) {
			sum += point[w];
		}
		sum /= q-2;
		cout << sum << endl;
		sum = 0; q = 0;
	}
	return 0;
}
