#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <deque>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <iomanip>
#include <utility>
#include <functional>
using namespace std;
#define ll long long
#define ull unsigned ll
deque<int> q;
int main() {
	int n;
	cin>>n;
	bool f=false;
	for (int i=0; i<n; i++) {
		int x;
		cin>>x;
		if (!f) {
			q.push_back(x);
		} else
			q.push_front(x);
		f=!f;
	}
	if (f)
		while (!q.empty()) {
			cout<<q.back()<<' ';
			q.pop_back();
		}
	else {
		while (!q.empty()) {
			cout<<q.front()<<' ';
			q.pop_front();
		}
	}
	return 0;
}