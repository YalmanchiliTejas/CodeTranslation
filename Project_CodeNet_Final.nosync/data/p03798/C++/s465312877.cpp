#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	string str;

	cin >> N >> str;
	
	vector<bool> res(N);
	bool tests[][2] = { {true, true}, {true, false}, {false, true}, {false, false} };

	bool result;
	for (int i = 0; i < 4; i++) {
		res[0] = tests[i][0];
		res[1] = tests[i][1];

		for (int k = 1; k < N-1; k++) {
			if (str[k] == 'o') {
				if (res[k])
					res[k + 1] = res[k - 1];
				else
					res[k + 1] = !res[k - 1];
			}
			else {
				if (res[k])
					res[k + 1] = !res[k - 1];
				else
					res[k + 1] = res[k - 1];
			}		
		}

		if (str[0] == 'o') {
			if (res[0])
				result = (res[1] == res[N - 1]);
			else
				result = !(res[1] == res[N - 1]);
		}
		else {
			if (res[0])
				result = !(res[1] == res[N - 1]);
			else
				result = (res[1] == res[N - 1]);
		}

		if (result) {
			if (str[N - 1] == 'o') {
				if (res[N - 1])
					result = (res[0] == res[N - 2]);
				else
					result = !(res[0] == res[N - 2]);
			}
			else {
				if (res[N - 1])
					result = !(res[0] == res[N - 2]);
				else
					result = (res[0] == res[N - 2]);
			}
		}

		if (result)
			break;
	}

	if (!result)
		cout << -1 << endl;
	else {
		string str = string(N, ' ');
		for (int i = 0; i < N; i++)
			str[i] = (res[i] ? 'S' : 'W');
		cout << str << endl;
	}
}