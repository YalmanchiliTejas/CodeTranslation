//#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>


#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979
#define MAXI 7500000

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;


int main(void) {
	
	while (1) {
		string s;
		int line = 1;
		int now;
		int a, b, c, d;
		vector<string> t(10);
		string u;

		cin >> s;
		if (s[0] == '#') {
			break;
		}
		cin >> a >> b >> c >> d;

		FOR(i, 0, s.size() - 1) {
			//cout << i << endl;
			if (s[i] >= '1'&&s[i] <= '9') {
				FOR(j, 1, s[i] - '0') {
					t[line].push_back('.');
				}
			}
			if (s[i] == 'b') {
				t[line].push_back('b');
			}
			if (s[i] == '/') {
				line++;
			}
		}

		now = t[1].size();

		t[a][b - 1] = '.';
		t[c][d - 1] = 'b';

		int count = 0;
		char moji;
		FOR(i, 1, line) {
			count = 0;
			FOR(j, 0, now - 1) {
				if (t[i][j] == 'b') {
					if (count != 0) {
						moji = count + '0';
						u.push_back(moji);
						count = 0;
					}
					u.push_back('b');
				}
				else {
					count++;
				}
				if (j == now - 1 && count != 0) {
					moji = count + '0';
					u.push_back(moji);
				}
			}
			if (i != line) {
				u.push_back('/');
			}
		}
		
		cout << u << endl;

		//FOR(i, 1, line) {
		//	cout << t[i] << endl;
		//}

	}
	return 0;
}
