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
#include <numeric>

using namespace std;

#define mod 1000000007

int main(){
	int n;
	cin >> n;
	int a[100001];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	multiset<int> s;
	s.insert(-1);
	for(int i = 0; i < n; i++){
		auto itr = s.lower_bound(a[i]);
		itr--;
		while(itr != s.begin() && (*itr) == a[i]) itr--;
		if(itr != s.begin()){
			s.erase(itr);
		}
		s.insert(a[i]);
	}
	cout << s.size() - 1 << endl;
}