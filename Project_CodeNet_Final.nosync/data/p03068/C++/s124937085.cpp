#include<iostream>
#include <string>
#include <cstdlib> //絶対値利用のため
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)

//const int INF = INT_MAX / 2;

int main() {
	int n, k;
	string s;
	char t;
	cin >> n >> s >> k;
	t = s[k - 1];
	for (int i = 0; i < n; i++) {
		if (s[i] != t) cout << "*";
		else cout << s[i];
	}
	cout << endl;

	return 0;
}



