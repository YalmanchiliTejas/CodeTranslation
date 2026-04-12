#include <iostream>
using namespace std;

int main(void)
{
	int n, s;
	while (cin >> n, n){
		cin >> s;
		int ma, mi, sum;
		ma = mi = sum = s;
		
		for (int i = 1; i < n; i++){
			cin >> s;
			ma = max(s, ma);
			mi = min(s, mi);
			sum += s;
		}
		n -= 2;
		sum -= (ma + mi);
		
		int res = sum / n;
		
		cout << res << endl;
		
	}
	
	return 0;
}