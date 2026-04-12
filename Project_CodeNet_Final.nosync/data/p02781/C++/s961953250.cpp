#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int k;
	cin >> str >> k;

	long long ans = 0;
	long long t = 0;
	long long s = 0;
	switch (k) {
	case 1:
		if (str.length() == 1) {
			cout << (str[0] - 48) << endl;
			return 0;
		}
		ans = (str.length() - 1) * 9;
		ans += (str[0] - 48);
		break;
	case 2:
		if (str.length() == 1) {
			cout << 0 << endl;
			return 0;
		}
		else if (str.length() == 2) {
			t = (str[0] - 48) * 10 + (str[1] - 48);

			for (int i = 11; i <= t; i++) {
				if (i % 10 != 0) {
					ans++;
				}
			}

			break;
		}
		ans = (str.length() - 1) * (str.length() - 2) / 2;
		ans *= 81;
		ans += (str.length() - 1) * 9 * (str[0] - 48 - 1);
		for(int i = 1; i < str.length(); i++) {
			if (str[i] != '0') {
				for (int j = i+1; j < str.length(); j++) {
					ans += 9;
				}
				ans += str[i] - 48;
				cout << ans << endl;
				return 0;
			}
			
		}
		
		break;
	case 3:
		if (str.length() == 1 || str.length() == 2) {
			cout << 0 << endl;
			return 0;
		}
		else if (str.length() == 3) {
			t = (str[0] - 48) * 100 + (str[1] - 48) * 10 + (str[2] - 48);

			for (int i = 100; i <= t; i++) {
				if (i % 10 != 0 && (i / 10) % 10 != 0) {
					ans++;
				}
			}

			break;
		}
		ans = (str.length() - 1) * (str.length() - 2) * (str.length() - 3) / 6;
		ans *= 729;
		ans += ((str.length() - 1) * (str.length() - 2) / 2) * 81 * (str[0] - 48 - 1);
		for (int i = 1; i < str.length(); i++) {
			if (str[i] != '0') {
				t = str.length() - i;
				s = i;
				break;
			}
		}

		if (t == 1) {
			cout << ans << endl;
			return 0;
		}
		else if (t == 2) {
			t = (str[str.length() - 1] - 48) * 10 + (str[str.length() - 2] - 48);

			for (int i = 11; i <= t; i++) {
				if (i % 10 != 0) {
					ans++;
				}
			}

			break;
		}
		
		ans += ((t - 1) * (t - 2) / 2) * 81;
		ans += (t - 1) * 9 * (str[s] - 48 - 1);
		for (int i = s + 1; i < str.length(); i++) {
			if (str[i] != '0') {
				for (int j = i + 1; j < str.length(); j++) {
					ans += 9;
				}
				ans += str[i] - 48;
			}
			cout << ans << endl;
			return 0;
		}

		break;
	}

	cout << ans << endl;

	return 0;
}