#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string n;
int k, len;
long ans = 0;

void solve(int i,int now,int nonzero) {
	long tmp;
	if ( (i<0) || (nonzero<0) )return;
	int nokori = len - i - 1;

	if (n[i]-'0' == now) {
		if (i == len - 1) {
			if (nonzero != 0)return;
			tmp = 1;
//			cout << i << "[" << now << "] tmp = " << tmp << endl;
			ans += tmp;
		}
		else {
			for (int j = 0; j <= n[i + 1] - '0'; j++) {
				if (j == 0) {
					solve(i + 1, j, nonzero);
				}
				else {
					solve(i + 1, j, nonzero - 1);
				}
			}
		}
	}
	else {
		if(nonzero == 0) {
			tmp = 1;
		}
		else if (nonzero == 1) {
			tmp = 9 * nokori;
		}
		else if (nonzero == 2) {
			tmp = 81 * nokori*(nokori- 1) / 2;
		}
		else {
			tmp = 729 * nokori*(nokori-1)*(nokori-2) / 6;
		}
//		cout << i << "[" << now << "] tmp = " << tmp << endl;
		ans += tmp;
	}
	return;

}


int main()
{

	cin >> n;
	cin >> k;
	len = n.length();

	if (len < 2) {
		if (k == 1) {
			cout << n << endl;
		}
		else {
			cout << 0 << endl;
		}
		return 0;
	}

	solve(0, 0, k);
	for (int i = 1; i <= n[0] - '0'; i++) {
		solve(0, i, k - 1);
	}

	cout << ans << endl;
	return 0;
}
