
#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

long long num(long long n) {
	return pow(2, n + 2) - 3;
}

long long fff(long long n) {
	return pow(2, n+1) - 1;
}

long long uno(long long n, long long x) {
	if (n == 0)return 1;
	if (x == 1)return 0;
	if (x <= num(n - 1) + 1)return uno(n - 1, x - 1);
	if (x == num(n - 1) + 2)return fff(n - 1) + 1;
	if (x == num(n))return fff(n);
	return fff(n - 1) + uno(n - 1, x - num(n - 1) - 2)+1;
}


int main()
{
	long long n, x;
	cin >> n >> x;
	cout << uno(n, x)<<endl;
	
    return 0;

	
}