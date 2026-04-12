#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
#include<stack>
#include<sstream>
typedef long long ll;

#define pi 3.14159265358979323846
#define VI vector<int>
#define VLL vector<long long>
#define MAX max_element
#define MIN min_element
#define all(v) v.begin(), v.end()

using namespace std;

template<typename T>
T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}
template<typename T>
T lcm(T a, T b) {
	return a * b / gcd(a, b);
}

/*char r[4];
int yaju[4];
char op[3];
int sum = 0;
scanf("%s", r);
for (int i = 0;i < 4;i++) {
	yaju[i] = r[i] - '0';
}
*/

int main() {
	ll X, Y, Z; cin >> X >> Y >> Z;
	for (int i = 0;;i++) {
		if (Y * i + Z*i+Z > X) {
			cout << i-1 << endl;
			break;
		}
	}
}