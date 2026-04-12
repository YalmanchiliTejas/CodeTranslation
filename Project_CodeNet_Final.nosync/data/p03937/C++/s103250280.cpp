#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int32_t h, w;
	cin >> h >> w;

	char temp;
	int32_t count{ 0 };
	for (auto i = 0; i < h * w; ++i) {
		cin >> temp;
		count += (temp == '#' ? 1 : 0);
	}

	cout << (count == h + w - 1 ? "Possible" : "Impossible") << endl;
}
