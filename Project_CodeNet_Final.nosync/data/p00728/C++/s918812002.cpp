
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
typedef complex<int> P;
typedef pair<int,int> pii;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
template <class F, class T> void convert(const F &f, T &t){	stringstream ss; ss << f; ss >> t;}


bool solve(int n){
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>> a[i];
	
	sort(all(a));
	int ans = 0;
	for(int i=1;i<n-1;i++) ans += a[i];
	ans /= n-2;
	
	cout<< ans<< endl;
	return true;
}

int main(){
	cout.setf(ios::fixed); cout.precision(10);
	int n;
	while(cin>> n, n){
		solve(n);
	}
	return 0;
}

 