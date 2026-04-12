#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const double EPS = 1e-10;
//cout << fixed << std::setprecision(9)
//memset(a, 0, sizeof(a));
//--------------------------

int n;
deque<int> ans;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;

		if (i % 2) {
			ans.push_front(a);
		}
		else {
			ans.push_back(a);
		}
	}

	if (n % 2) {
		deque<int>::reverse_iterator ritr;
		for (ritr = ans.rbegin();ritr != ans.rend();ritr++) {
			cout << *ritr << " ";
		}
		cout << endl;
	}
	else {
		deque<int>::iterator itr;
		for (itr = ans.begin();itr != ans.end();itr++) {
			cout << *itr << " ";
		}
		cout << endl;
	}

	return 0;
}
