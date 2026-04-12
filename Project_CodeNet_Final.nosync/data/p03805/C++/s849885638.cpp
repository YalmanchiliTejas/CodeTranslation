#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <stdio.h>
#include <bitset>
#include<math.h>
#include<list>
#include<map>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979323846  
typedef pair<int, int> P;

int main() {
	vector<P> p;
	vector<int> v;
	int n, m,a,b,ans=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		p.push_back(P(a, b));
	}
	for (int i = 2; i <= n; i++) {
		v.push_back(i);
	}
	do {
		int now = 1;
		bool flag = true;
		for (int i = 0; i < n - 1&&flag; i++) {
			flag = false;
			for (int j = 0; j < m; j++) {
				if ((p.at(j).first == now && p.at(j).second == v.at(i))|| (p.at(j).first == v.at(i) && p.at(j).second == now)) {
					flag = true;
				}
			}
			/*if (!flag) {
				cout << now << v.at(i) << endl;
			}*/
			now = v.at(i);
		}
		if (flag) {
			ans++;
		}
	} while (std::next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}
