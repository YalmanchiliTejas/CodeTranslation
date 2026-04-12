#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
#define ll long long
#define ld long double
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N, 0);
	for(int i=0; i<N; ++i) cin >> a[i];
	multiset<int> st;
	for(int i=0; i<N; ++i){
	    auto itr=st.lower_bound(a[i]);
	    if(itr==st.begin()){
	        st.insert(a[i]);
	    }else{
	        --itr;
	        auto del=itr;
	        ++del;
	        st.erase(itr, del);
	        st.insert(a[i]);
	    }
	}
	cout << st.size() << endl;
	return 0;
}
