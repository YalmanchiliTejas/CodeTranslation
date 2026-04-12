#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
#include <fstream>

using namespace std;
typedef long long Int;
#define REP(i , x) for(int i = 0 ; i < x ; ++i)


int main()
{
	int n;
	while (cin >> n, n){
		int dise[4][3] = { { 0, 5, 0 }, { 4, 1, 3 }, { 0, 2, 0 }, { 0, 6, 0 } };
		int ans(1);
		vector<string> com;
		REP(i, n){
			string a;
			cin >> a;
			com.push_back(a);
		}

		for (auto x : com){
			if (x == "North"){
				int now = dise[2][1];
				dise[2][1] = dise[3][1];
				dise[3][1] = dise[0][1];
				dise[0][1] = dise[1][1];
				dise[1][1] = now;
				ans += now;
			}
			if (x == "East"){
				int now = dise[1][0];
				dise[1][0] = dise[3][1];
				dise[3][1] = dise[1][2];
				dise[1][2] = dise[1][1];
				dise[1][1] = now;
				ans += now;
			}
			if (x == "West"){
				int now = dise[1][2];
				dise[1][2] = dise[3][1];
				dise[3][1] = dise[1][0];
				dise[1][0] = dise[1][1];
				dise[1][1] = now;
				ans += now;
			}
			if (x == "South"){
				int now = dise[0][1];
				dise[0][1] = dise[3][1];
				dise[3][1] = dise[2][1];
				dise[2][1] = dise[1][1];
				dise[1][1] = now;
				ans += now;
			}
			if (x == "Left"){
				int temp = dise[2][1];
				dise[2][1] = dise[1][0];
				dise[1][0] = dise[0][1];
				dise[0][1] = dise[1][2];
				dise[1][2] = temp;
				ans += dise[1][1];
			}
			if (x == "Right"){
				int temp = dise[2][1];
				dise[2][1] = dise[1][2];
				dise[1][2] = dise[0][1];
				dise[0][1] = dise[1][0];
				dise[1][0] = temp;
				ans += dise[1][1];
			}
		}

		cout << ans << endl;
	}

	return 0;
}