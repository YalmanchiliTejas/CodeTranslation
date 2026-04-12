#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

#define REP(i,n) for(int i=0; i < n; ++i)
#define EACH(it,c) for(decltype((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

int main() {
	std::ios::sync_with_stdio();

	int m;
	cin >> m; 
	REP(i,m) {
		int firstMoney, year, n;
		cin >> firstMoney;
		cin >> year;
		cin >> n;
		
		int result = 0;
		REP(j,n) {
			int type, addition;
			double percent;
			cin >> type >> percent >> addition;

			// calc
			int tmpMoney = firstMoney;
			int benefit = 0;
			if(type) {
				REP(k, year) {
					tmpMoney = tmpMoney * (1.0 + percent) - addition;
				}
				result = max(result, tmpMoney);
			} else {
				REP(k, year) {
					benefit += tmpMoney * percent;
					tmpMoney -= addition;
				}
				result = max(result, tmpMoney + benefit);
			}
		}
		cout << result << endl; 
	}
	return 0;
}