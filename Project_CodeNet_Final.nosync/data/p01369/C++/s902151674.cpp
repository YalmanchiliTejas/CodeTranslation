#include <iostream>
#include <cstring>
using namespace std;

char str[33];

int main(void) {
	int count;

	cin.tie(0);

	while (cin >> str, str[0] != '#') {
		count = 0;

		for (int i = 0; i < 31; i++) {
			if (strlen(str) - 1 == i) break;

			if ((('a' <= str[i] && str[i] <= 'g') | ('q' <= str[i] && str[i] <= 't') | ('v' <= str[i] && str[i] <= 'x') | str[i] == 'z') && ( ('h' <= str[i + 1] && str[i + 1] <= 'p') | (str[i + 1] == 'u' | str[i + 1] == 'y'))) {
				count++;
			} else if ((('a' <= str[i + 1] && str[i + 1] <= 'g') | ('q' <= str[i + 1] && str[i + 1] <= 't') | ('v' <= str[i + 1] && str[i + 1] <= 'x') | str[i + 1] == 'z') && ( ('h' <= str[i] && str[i] <= 'p') | (str[i] == 'u' | str[i] == 'y'))) {
				count++;
			}

		}
		cout << count << "\n";
	}
	return 0;
}