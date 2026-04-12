#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int num = a * 100 + b * 10 + c;
	if (num % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}