#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <functional>


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

using namespace std;
static const double EPS = 1e-6;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;


int main(){
	vector<Pii> v;
	int c1,c2;
	while(scanf("%d,%d",&c1,&c2),c1||c2) v.push_back(Pii(c2,c1));
	sort(v.begin(),v.end(),greater<Pii>());
	vector<int> v2((int)v.size());
	int last = INT_MAX,cnt = 0;
	for (int i = 0; i < (int)v.size(); i++){
		if(last != v[i].first) last = v[i].first,cnt++;
		v2[v[i].second - 1] = cnt;
	}
	int c;
	while(cin>>c) cout << v2[c - 1] << endl;
	return 0;
}