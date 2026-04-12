#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <functional>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
	deque<int> dq;
    int i;
    int x; 
    bool fr = true;
    for(i = 0; i < n; i++) {
		cin >> x;
		if(fr) {
			dq.push_back(x);
		}
		else {
			dq.push_front(x);
		}
		fr = !fr;
	}
	if(fr) {
		for(i = 0; i < n; i++) {
			cout << dq[i] << " ";
		}
	}
	else {
		for(i = n - 1; i >= 0; i--) {
			cout << dq[i] << " ";
		}
	}
	
	
    return 0;
}

