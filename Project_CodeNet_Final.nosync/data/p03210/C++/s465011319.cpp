#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<functional>
#include<stack>
#include<queue>
#include<cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef std::pair<int, int> int_pair;
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }


int main() {
	int a = 0;
	cin >> a;
	if (a == 7 || a == 5 || a == 3) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
