#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cinttypes>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<stack>


#define FSCNd64 "%" SCNd64
#define FPRId64 "%" PRId64

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;

#define PI 3.1415926535897932384626433832795

template<typename X>
bool max_u(X&m, X v)
{
	if(m<v)
	{
		m=v;
		return true;
	}
	return false;
}


template<typename X>
bool min_u(X&m, X v)
{
	if(m>v)
	{
		m=v;
		return true;
	}
	return false;
}


struct solve
{
	solve(){}
	ll operator()() {
		return 0;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(;;)
	{
		int x;
		cin >> x;
		if(cin.fail()) break;
		bool ans=(x>=30);
		cout << (ans?"Yes":"No") << "\n";
	}
	return 0;
}
