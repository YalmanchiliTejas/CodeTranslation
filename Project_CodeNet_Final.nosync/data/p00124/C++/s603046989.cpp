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
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (int)(count); i++)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 100000 ;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

using namespace std;

bool CMP(const pair<int,string>&x, const pair<int,string>&y){
	return x.first > y.first;
}

int main()
{
	int n;
	bool b = false;
	while(cin>>n,n){
		vector<pair<int,string> > v;
		while(n--){
			string s; int a,b,c;
			cin>>s>>a>>b>>c;
			v.push_back(make_pair(a*3+c,s));
		}

		stable_sort(v.begin(),v.end(),CMP);
		if(b) cout << endl;
		b = true;
		FOR(i,sz(v)){
			cout << v[i].second << "," << v[i].first << endl;
		}
	}

	return 0;
}