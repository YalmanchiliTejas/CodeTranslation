#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#define ll long long
#define oku7 1000000007
using namespace std;


int main() {
	int N;
	vector<int> l,moto;
	cin >> N;
	l.reserve(200000);
	moto.reserve(200000);
	for (int i = 0; i < N; i++) {
		int x;
		//cin >> x;
		scanf("%d", &x);
		l.push_back(x);
		moto.push_back(x);
	}


	sort(l.begin(), l.end());
	
	for (int i = 0; i < N; i++) {
		//int ind = binSearch(l, moto[i]);
		int mid = l[N / 2];
		if (moto[i] < mid) {
			//cout << l[N / 2]<< "\n";
			printf("%d\n", l[N / 2]);
		}
		else {
			//cout << l[N / 2 - 1] << "\n";
			printf("%d\n", l[N / 2-1]);
		}
	}
	

	return 0;
}