#include <iostream>
#include <string>
using namespace std;

string s;
int k, m = 0, t, u;

int main()
{
	cin >> s >> k;

	t = s.size();
	u = s[0] - '0';

	if (t > k) {
		if (k == 1)
			m = 9 * (t - 1);
		else if (k == 2)
			m = 81 * (t - 1) * (t - 2) / 2;
		else
			m = 243 * (t - 1) * (t - 2) * (t - 3) / 2;
	}

	if (t >= k) {
		if (k == 1)
			m += u;
		else if (k == 2) {
			m += (u - 1) * 9 * (t - 1);

			int i = 1;
			while (i < t && s[i] == '0')
				i++;

			if (i < t) {
				int v = s[i] - '0';

				m += 9 * (t - i - 1) + v;
			}
		}
		else {
			m += (u - 1) * 81 * (t - 1) * (t - 2) / 2;

			int i = 1;
			while (i < t && s[i] == '0')
				i++;

			if (i < t - 1) {
				int v = s[i] - '0';

				m += 81 * (t - i - 1) * (t - i - 2) / 2 + (v - 1) * 9 * (t - i - 1);

				int j = i + 1;
				while (j < t && s[j] == '0')
					j++;

				if (j < t) {
					int w = s[j] - '0';

					m += 9 * (t - j - 1) + w;
				}
			}
		}
	}

	cout << m << endl;

	return 0;
}