#include <bits/stdc++.h>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;

int main(void) {
	
	while (1) {
		string s;
		bool flag;
		int count = 0;

		cin >> s;

		if (s[0] == '#') {
			break;
		}
		switch (s[0]) {
		case 'q':
		case 'w':
		case 'e':
		case 'r':
		case 't':
		case 'a':
		case 's':
		case 'd':
		case 'f':
		case 'g':
		case 'z':
		case 'x':
		case 'c':
		case 'v':
		case 'b':
			flag = false;
			break;
		default:
			flag = true;
			break;
		}
		FOR(i, 1, s.size() - 1) {
			switch (s[i]) {
			case 'q':
			case 'w':
			case 'e':
			case 'r':
			case 't':
			case 'a':
			case 's':
			case 'd':
			case 'f':
			case 'g':
			case 'z':
			case 'x':
			case 'c':
			case 'v':
			case 'b':
				if (flag) {
					count++;
				}
				flag = false;
				break;
			default:
				if (!flag) {
					count++;
				}
				flag = true;
				break;
			}
		}
		cout << count << endl;
	}
	
}
