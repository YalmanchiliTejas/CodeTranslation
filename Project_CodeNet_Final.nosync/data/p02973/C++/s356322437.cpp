#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;


const int BIG_INT = 1000000000;
const ll BIG_NUM = 1000000000000000000;



int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	multiset<int> ms;
	for (int i = 0; i < n; i++) {
		if (ms.size() > 0) {
		
			auto it = ms.upper_bound(-a[i]);

			if (it != ms.end()){
				
				ms.erase(it);
			}
		}

		ms.insert(-a[i]);
	}


	
	cout << ms.size() << endl;
}

