

#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << a[0] << endl;
		return 0;
	}

	int index = n-1;
	
	while (true) {
			cout << a[index];

			index -= 2;

			cout << " ";

			if (index < 0) {
				break;
			}

		
	}

	if (n % 2 == 0) {
		index = 0;
	}
	else {
		index = 1;
	}
	

	while (true) {
		cout << a[index];

		index += 2;
		if (index > n-1) {
			break;
		}

		cout << " ";
	}

	cout << endl;

	
}