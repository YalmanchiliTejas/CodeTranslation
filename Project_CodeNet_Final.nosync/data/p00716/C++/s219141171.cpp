#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int testcase;
	cin >> testcase;
	while (testcase--){
		int money, year, n;
		int ret = 0;
		cin >> money >> year >> n;
		while (n--){
			int type, charge, tmp = money;
			long double per;
			cin >> type >> per >> charge;
			// 単利
			if (type == 0){
				int a = 0;
				for (int i = 0; i < year; i++){
					a += floor((tmp * per));
					tmp -= charge;
				}
				ret = max(ret, a + tmp);
			}
			// 複利
			else {
				for (int i = 0; i < year; i++){
					tmp += floor((tmp * per));
					tmp -= charge;
				}
				ret = max(ret, tmp);
			}
		}
		cout << ret << endl;
	}

	return 0;
}