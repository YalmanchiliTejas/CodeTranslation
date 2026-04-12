#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	deque<int> qu;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(i % 2 == 0) qu.push_back(a);
		else qu.push_front(a);
	}
	if(n % 2 == 0){
		for(int i = 0; i < n; i++){
			cout << qu[i];
			if(i == n - 1) cout << endl;
			else cout << " ";
		}
	} else {
		for(int i = n - 1; i >= 0; i--){
			cout << qu[i];
			if(i == 0) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}