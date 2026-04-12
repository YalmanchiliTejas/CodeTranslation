#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	multiset<int> st;

	for(int i = 0;i < n;i++){
		int a;
		cin >> a;

		auto p = st.lower_bound(a);
		if(p != st.begin()){
			p--;
			st.erase(p);
		}
		st.insert(a);
	}

	cout << st.size() << endl;
}
