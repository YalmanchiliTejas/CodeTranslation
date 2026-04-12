#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef queue<int, int> qii;
typedef pair<int, int> pii;

#define PI 3.14159265359
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repz(i,n) rep(i,0,n)

//int型を受け取ってその桁数を返す
int check_digits(int n) {
	int digits = 0;
	while (n != 0) {
		n /= 10;
		digits++;
	}
	return digits;
}

//int型を受け取ってその各桁の和を返す
int sum_digits(int n) {
	int sum=0;
	int N = n;
	while (N) {
		sum += N % 10;
		N /= 10;
	}
	return sum;
}


//最大公約数を返す関数
int gcd(int n, int m) {
	while (n != 0) {
		if (n < m) swap(n, m);
		n = n % m;
	}
	return m;
}


//2点間の距離を返す
float dis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}


int main() {
	int n,temp, top = 0, ans = 0;
	cin >> n;
	repz(i, n) {
		cin >> temp;
		if (temp >= top) {
			top = temp;
			ans++;
		}
	}
	
	cout << ans << endl;

	system("pause");
	return 0;
}
