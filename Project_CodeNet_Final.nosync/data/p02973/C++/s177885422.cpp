#include <iostream>
#include <deque>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
	int N;
	deque<int> d;

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < N; i++) {
		int p = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
		if (p == 0) {
			d.push_front(v[i]);
		} else {
			d[p - 1] = v[i];
		}
	}

	cout << d.size() << endl;

	return 0;
}