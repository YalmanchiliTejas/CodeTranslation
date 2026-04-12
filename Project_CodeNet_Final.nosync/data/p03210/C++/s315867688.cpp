#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

#define INT_MAX 2147483647

long gcd(long m, long n);
long lcm(long m, long n);

int main( void ){

	int n;
	cin >> n;
	string str = "NO";
	if( n == 7 || n == 5 || n == 3 ) str = "YES";
	cout << str;
	return 0;

}

//最大公倍数
long gcd(long m, long n)
{
	long temp;
	while (m % n != 0)
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}

//最小公倍数
long lcm(long m, long n)
{
	return m * n / gcd(m,n); 
}