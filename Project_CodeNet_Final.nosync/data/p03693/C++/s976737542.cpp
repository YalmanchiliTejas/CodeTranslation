#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;

int main()
{
	int r, g, b;
	int sum = 0;
	cin >> r >> g >> b;
	sum += r * 100 + g * 10 + b;
	if (sum % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return	0;
}