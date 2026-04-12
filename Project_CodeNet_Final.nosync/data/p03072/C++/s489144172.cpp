#include<iostream>
#include<functional>
#include<utility>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n, m;
string s;



int main() {
	cin >> n;
	vector<int> vec(n);
	int max = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		if (max<vec[i])
		{
			max = vec[i];
		}
		if (vec[i] >= max) {
			ans++;
		}
	}
	cout << ans << endl;
}