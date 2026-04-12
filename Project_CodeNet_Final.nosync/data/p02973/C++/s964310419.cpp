
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iterator>
#include <deque>
#include <string>
#include <queue>
#include <omp.h>
#include <fstream>   // ifstream, ofstream
typedef int64_t ll;
using namespace std;
const ll INF=1e10;
const double EPS=1e-8;
const ll mod = 1000000007;
int main(){
	ll n;
	cin>>n;
	vector<ll> a;
	for(ll i1=0;i1<n;i1++){
		ll temp;
		cin>>temp;
		a.push_back(temp);
	}
	multiset<ll> current_situation;
	current_situation.insert(a[0]);
	for(ll i1=1;i1<n;i1++){
		auto iter = current_situation.lower_bound(a[i1]);
		if(iter==current_situation.begin()){
			current_situation.insert(a[i1]);
		}else{
			--iter;
			current_situation.erase(iter);
			current_situation.insert(a[i1]);
		}
	}
	cout<<current_situation.size()<<endl;
}
