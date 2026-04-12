#include "iostream"
#include "vector"
#include "array"
#include "string"
#include "algorithm"

using namespace std;
#define rep(p,q) for(int i = p;i < q;i++)

//ICPC Score Totalizer Software
int main(void) {
	int num = 0;
	while (cin >> num && num != 0) {
		vector<int> v = vector<int>();
		int point = 0;
		rep(0, num) {
			cin >> point;
			v.push_back(point);
		}
		sort(v.begin(), v.end());
		int sum = 0;
		rep(1, num - 1) {
			sum += v[i];
		}
		cout << sum / (num - 2) << endl;
	}
}
