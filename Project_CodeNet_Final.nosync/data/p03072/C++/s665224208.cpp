#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<tuple>
#include<utility>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
#define rep(i,n,x) for(int i=n;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define pb push_back
#define mp make_pair

int main() {
	int n, h = 0, count = 0;
	cin >> n;
	rep(i, 0, n) {
		int H;
		cin >> H;
		if (h <= H) {
			count++;
		}
		h = max(h, H);
	}
	cout << count << endl;
	return 0;
}